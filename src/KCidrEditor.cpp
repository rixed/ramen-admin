#include <cassert>

#include <QHBoxLayout>
#include <QLabel>

#include "desssergen/sync_value.h"
#include "MakeSyncValue.h"
#include "KIntEditor.h"
#include "KIpEditor.h"

#include "KCidrEditor.h"

KCidrEditor::KCidrEditor(QWidget *parent, bool allow_v4, bool allow_v6)
  : AtomicWidget(parent),
    allowV4(allow_v4),
    allowV6(allow_v6)
{
  ipEditor = new KIpEditor(allowV4, allowV6);
  int const max_mask { allowV6 ? 128 : 32 };
  maskEditor = new KIntEditor(u8OfQString, nullptr, 0, max_mask);

  QHBoxLayout *layout = new QHBoxLayout;
  layout->addWidget(ipEditor);
  layout->addWidget(new QLabel("/"));
  layout->addWidget(maskEditor);
  QWidget *w = new QWidget;
  w->setLayout(layout);
  relayoutWidget(w);

  connect(ipEditor, &KIpEditor::inputChanged,
          this, &KCidrEditor::inputChanged);
  connect(maskEditor, &KIntEditor::inputChanged,
          this, &KCidrEditor::inputChanged);
}

std::shared_ptr<dessser::gen::sync_value::t const> KCidrEditor::getValue() const
{
  // Both ip and mask will be sync_values, extract the actual ip and mask:
  std::shared_ptr<dessser::gen::sync_value::t const> ip_ { ipEditor->getValue() };
  if (! ip_) return nullptr;
  Q_ASSERT(ip_->index() == dessser::gen::sync_value::RamenValue);
  std::shared_ptr<dessser::gen::raql_value::t const> ip {
    std::get<dessser::gen::sync_value::RamenValue>(*ip_) };
  // More specifically, mask will be an u8:
  std::shared_ptr<dessser::gen::sync_value::t const> mask_ { maskEditor->getValue() };
  if (! mask_) return nullptr;
  Q_ASSERT(mask_->index() == dessser::gen::sync_value::RamenValue);
  std::shared_ptr<dessser::gen::raql_value::t const> mask__ {
    std::get<dessser::gen::sync_value::RamenValue>(*mask_) };
  Q_ASSERT(mask__->index() == dessser::gen::raql_value::VU8);
  uint8_t const mask { std::get<dessser::gen::raql_value::VU8>(*mask__) };

  uint32_t ipv4;
  uint128_t ipv6;

  if (allowV4 && allowV6) {
    // returns a Cidr from the Ip
    switch (ip->index()) {
      case dessser::gen::raql_value::VIp:
        {
          auto const &ip_ { std::get<dessser::gen::raql_value::VIp>(*ip) };
          if (ip_.index() == dessser::gen::raql_value::v4) {
            ipv4 = std::get<dessser::gen::raql_value::v4>(ip_);
            return makeRamenValue(std::make_shared<dessser::gen::raql_value::t>(
              std::in_place_index<dessser::gen::raql_value::VCidr>,
              std::in_place_index<dessser::gen::raql_value::v4>,
              ipv4, mask));
          } else {
            Q_ASSERT(ip_.index() == dessser::gen::raql_value::v6);
            ipv6 = std::get<dessser::gen::raql_value::v6>(ip_);
            return makeRamenValue(std::make_shared<dessser::gen::raql_value::t>(
              std::in_place_index<dessser::gen::raql_value::VCidr>,
              std::in_place_index<dessser::gen::raql_value::v6>,
              ipv6, mask));
          }
        }
      case dessser::gen::raql_value::VIpv4:
        ipv4 = std::get<dessser::gen::raql_value::VIpv4>(*ip);
        return makeRamenValue(std::make_shared<dessser::gen::raql_value::t>(
          std::in_place_index<dessser::gen::raql_value::VCidr>,
          std::in_place_index<dessser::gen::raql_value::v4>,
          ipv4, mask));
      case dessser::gen::raql_value::VIpv6:
        ipv6 = std::get<dessser::gen::raql_value::VIpv6>(*ip);
        return makeRamenValue(std::make_shared<dessser::gen::raql_value::t>(
          std::in_place_index<dessser::gen::raql_value::VCidr>,
          std::in_place_index<dessser::gen::raql_value::v6>,
          ipv6, mask));
      default:
        qFatal("Invalid ip->index()");
    }
  } else if (allowV4) {
    // returns a Cidrv4 from the Ipv4
    ipv4 = std::get<dessser::gen::raql_value::VIpv4>(*ip);
    return makeRamenValue(std::make_shared<dessser::gen::raql_value::t>(
      std::in_place_index<dessser::gen::raql_value::VCidrv4>,
      ipv4, mask));
  } else if (allowV6) {
    // returns a Cidrv6 from the Ipv6
    ipv6 = std::get<dessser::gen::raql_value::VIpv6>(*ip);
    return makeRamenValue(std::make_shared<dessser::gen::raql_value::t>(
      std::in_place_index<dessser::gen::raql_value::VCidrv6>,
      ipv6, mask));
  } else {
    return nullptr;
  }
}

void KCidrEditor::setEnabled(bool enabled)
{
  ipEditor->setEnabled(enabled);
  maskEditor->setEnabled(enabled);
}

bool KCidrEditor::setValue(
  std::shared_ptr<dessser::gen::sync_value::t const> v)
{
  // Extract the IP and mask as sync_values
  std::shared_ptr<dessser::gen::sync_value::t const> ip, mask;
  Q_ASSERT(v->index() == dessser::gen::sync_value::RamenValue);
  std::shared_ptr<dessser::gen::raql_value::t const> rv {
    std::get<dessser::gen::sync_value::RamenValue>(*v) };
  switch (rv->index()) {
    case dessser::gen::raql_value::VCidrv4:
      Q_ASSERT(allowV4);
      {
        auto const &cidr { std::get<dessser::gen::raql_value::VCidrv4>(*rv) };
        ip = ofIpv4(cidr.Cidr4_ip);
        mask = ofU8(cidr.Cidr4_mask);
      }
      break;
    case dessser::gen::raql_value::VCidrv6:
      Q_ASSERT(allowV6);
      {
        auto const &cidr { std::get<dessser::gen::raql_value::VCidrv6>(*rv) };
        ip = ofIpv6(cidr.ip);
        mask = ofU8(cidr.mask);
      }
      break;
    case dessser::gen::raql_value::VCidr:
      Q_ASSERT(allowV4 && allowV6);
      {
        auto const &cidr { std::get<dessser::gen::raql_value::VCidr>(*rv) };
        switch (cidr.index()) {
          case dessser::gen::raql_value::v4:
            {
              auto const &cidrv4 { std::get<dessser::gen::raql_value::v4>(cidr) };
              ip = ofIpv4(cidrv4.Cidr4_ip);
              mask = ofU8(cidrv4.Cidr4_mask);
            }
            break;
          case dessser::gen::raql_value::v6:
            {
              auto const &cidrv6 { std::get<dessser::gen::raql_value::v6>(cidr) };
              ip = ofIpv4(cidrv6.ip);
              mask = ofU8(cidrv6.mask);
            }
            break;
          default:
            Q_ASSERT(false);
        }
      }
      break;
    default:
      Q_ASSERT(false);
  }

  /* Take care not to shortcut setting the second value when the first returns
   * true :) */
  bool s1 { ipEditor->setValue(ip) };
  bool s2 { maskEditor->setValue(mask) };
  bool res { s1 || s2 };

  if (res) emit valueChanged(v);
  return res;
}
