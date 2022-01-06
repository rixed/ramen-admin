// vim: sw=2 ts=2 sts=2 expandtab tw=80
static int parseUrl(QString &host, quint16 &port, QString const &url) {
  qsizetype const sep{url.indexOf(':')};

  if (sep < 0) {
    host = url;
    port = 29340;
  } else {
    host = url.mid(0, sep);
    bool ok;
    port = url.mid(sep + 1).toInt(&ok);
    if (!ok) return -1;
  }

  return 0;
}
