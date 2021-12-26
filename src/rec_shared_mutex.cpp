// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "rec_shared_mutex.h"

thread_local int rec_shared_mutex::count = 0;
