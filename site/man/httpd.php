<? include "header.php" ?>

<h1 align=center>ramen-httpd</h1>



<a name="NAME"></a>
<h2>NAME</h2>


<p style="margin-left:11%; margin-top: 1em">Ramen-httpd -
Start an HTTP server</p>

<a name="SYNOPSIS"></a>
<h2>SYNOPSIS</h2>


<p style="margin-left:11%; margin-top: 1em"><b>Ramen
httpd</b> [<i>OPTION</i>]...</p>

<a name="OPTIONS"></a>
<h2>OPTIONS</h2>



<p style="margin-left:11%; margin-top: 1em"><b>--api-v1</b>[=<i>VAL</i>]
(default=)</p>

<p style="margin-left:17%;">Implement ramen API over
http</p>

<p style="margin-left:11%;"><b>--bundle-dir</b>=<i>VAL</i>
(absent=/usr/lib/ramen/bundle/ or <b>RAMEN_BUNDLE_DIR</b>
<br>
env)</p>

<p style="margin-left:17%;">Directory where to find
libraries for the embedded compiler</p>

<p style="margin-left:11%;"><b>--daemonize</b> (absent
<b>RAMEN_DAEMONIZE</b> env)</p>

<p style="margin-left:17%;">Daemonize</p>


<p style="margin-left:11%;"><b>--fault-injection-rate</b>=<i>VAL</i>
(absent=1e-06 or <b>RAMEN_FAULT_INJECTION_RATE</b> <br>
env)</p>

<p style="margin-left:17%;">Rate at which to generate fake
errors</p>

<p style="margin-left:11%;"><b>--graphite</b>[=<i>VAL</i>]
(default=)</p>

<p style="margin-left:17%;">Impersonate graphite for
Grafana</p>

<p style="margin-left:11%;"><b>--help</b>[=<i>FMT</i>]
(default=auto)</p>

<p style="margin-left:17%;">Show this help in format
<i>FMT</i>. The value <i>FMT</i> must be one of
&lsquo;auto', &lsquo;pager', &lsquo;groff' or &lsquo;plain'.
With &lsquo;auto', the format is &lsquo;pager&lsquo; or
&lsquo;plain' whenever the <b>TERM</b> env var is
&lsquo;dumb' or undefined.</p>


<p style="margin-left:11%;"><b>--max-simultaneous-compilations</b>=<i>VAL</i>,
<b>--max-simult-compilations</b>=<i>VAL</i> <br>
(absent=4 or <b>RAMEN_MAX_SIMULT_COMPILATIONS</b> env)</p>

<p style="margin-left:17%;">Max number of compilations to
perform simultaneously</p>

<p style="margin-left:11%;"><b>--solver</b>=<i>VAL</i>,
<b>--smt-solver</b>=<i>VAL</i> (absent=z3 -t:20000 -smt2 %s
or <b><br>
RAMEN_SMT_SOLVER</b> env)</p>

<p style="margin-left:17%;">Command to run the SMT solver
(with %s in place of the SMT2 file name)</p>

<p style="margin-left:11%;"><b>--to-stdout</b>,
<b>--to-stderr</b>, <b>--stdout</b>, <b>--stderr</b> (absent
<b><br>
RAMEN_LOG_TO_STDERR</b> env)</p>

<p style="margin-left:17%;">Log onto stdout/stderr instead
of a file</p>

<p style="margin-left:11%;"><b>--to-syslog</b>,
<b>--syslog</b> (absent <b>RAMEN-LOG-SYSLOG</b> env)</p>

<p style="margin-left:17%;">log using syslog</p>

<p style="margin-left:11%;"><b>--url</b>=<i>VAL</i>
(absent=http://127.0.0.1:8080 or <b>RAMEN_URL</b> env)</p>

<p style="margin-left:17%;">URL to reach the HTTP
service</p>


<p style="margin-left:11%;"><b>--use-external-compiler</b>,
<b>--external-compiler</b> (absent <b><br>
RAMEN_USE_EMBEDDED_COMPILER</b> env)</p>

<p style="margin-left:17%;">Call external compiler rather
than using embedded one</p>

<p style="margin-left:11%;"><b>--version</b></p>

<p style="margin-left:17%;">Show version information.</p>

<a name="COMMON OPTIONS"></a>
<h2>COMMON OPTIONS</h2>


<p style="margin-left:11%; margin-top: 1em"><b>-d</b>,
<b>--debug</b> (absent <b>RAMEN_DEBUG</b> env)</p>

<p style="margin-left:17%;">Increase verbosity</p>


<p style="margin-left:11%;"><b>--initial-export-duration</b>=<i>VAL</i>
(absent=0. or <b>RAMEN_INITIAL_EXPORT</b> env)</p>

<p style="margin-left:17%;">How long to export a node
output after startup before a client asks for it</p>


<p style="margin-left:11%;"><b>--persist-dir</b>=<i>VAL</i>
(absent=/tmp/ramen or <b>RAMEN_PERSIST_DIR</b> env)</p>

<p style="margin-left:17%;">Directory where are stored data
persisted on disc</p>

<p style="margin-left:11%;"><b>-q</b>, <b>--quiet</b>
(absent <b>RAMEN_QUIET</b> env)</p>

<p style="margin-left:17%;">Decrease verbosity</p>

<p style="margin-left:11%;"><b>-S</b>,
<b>--keep-temp-files</b> (absent
<b>RAMEN_KEEP_TEMP_FILES</b> env)</p>

<p style="margin-left:17%;">Keep temporary files</p>

<p style="margin-left:11%;"><b>--seed</b>=<i>VAL</i>,
<b>--rand-seed</b>=<i>VAL</i> (absent
<b>RAMEN_RANDOM_SEED</b> env)</p>

<p style="margin-left:17%;">Seed to initialize the random
generator with (will use a random one if unset)</p>

<p style="margin-left:11%;"><b>--variant</b>=<i>VAL</i>
(absent <b>RAMEN_VARIANTS</b> env)</p>

<p style="margin-left:17%;">Force variants</p>

<a name="ENVIRONMENT"></a>
<h2>ENVIRONMENT</h2>


<p style="margin-left:11%; margin-top: 1em">These
environment variables affect the execution of <b>httpd</b>:
<b><br>
RAMEN-LOG-SYSLOG</b></p>

<p style="margin-left:17%;">See option
<b>--to-syslog</b>.</p>

<p style="margin-left:11%;"><b>RAMEN_BUNDLE_DIR</b></p>

<p style="margin-left:17%;">See option
<b>--bundle-dir</b>.</p>

<p style="margin-left:11%;"><b>RAMEN_DAEMONIZE</b></p>

<p style="margin-left:17%;">See option
<b>--daemonize</b>.</p>

<p style="margin-left:11%;"><b>RAMEN_DEBUG</b></p>

<p style="margin-left:17%;">See option <b>--debug</b>.</p>


<p style="margin-left:11%;"><b>RAMEN_FAULT_INJECTION_RATE</b></p>

<p style="margin-left:17%;">See option
<b>--fault-injection-rate</b>.</p>


<p style="margin-left:11%;"><b>RAMEN_INITIAL_EXPORT</b></p>

<p style="margin-left:17%;">See option
<b>--initial-export-duration</b>.</p>


<p style="margin-left:11%;"><b>RAMEN_KEEP_TEMP_FILES</b></p>

<p style="margin-left:17%;">See option
<b>--keep-temp-files</b>.</p>

<p style="margin-left:11%;"><b>RAMEN_LOG_TO_STDERR</b></p>

<p style="margin-left:17%;">See option
<b>--to-stderr</b>.</p>


<p style="margin-left:11%;"><b>RAMEN_MAX_SIMULT_COMPILATIONS</b></p>

<p style="margin-left:17%;">See option
<b>--max-simult-compilations</b>.</p>

<p style="margin-left:11%;"><b>RAMEN_PERSIST_DIR</b></p>

<p style="margin-left:17%;">See option
<b>--persist-dir</b>.</p>

<p style="margin-left:11%;"><b>RAMEN_QUIET</b></p>

<p style="margin-left:17%;">See option <b>--quiet</b>.</p>

<p style="margin-left:11%;"><b>RAMEN_RANDOM_SEED</b></p>

<p style="margin-left:17%;">See option <b>--seed</b>.</p>

<p style="margin-left:11%;"><b>RAMEN_SMT_SOLVER</b></p>

<p style="margin-left:17%;">See option
<b>--smt-solver</b>.</p>

<p style="margin-left:11%;"><b>RAMEN_URL</b></p>

<p style="margin-left:17%;">See option <b>--url</b>.</p>


<p style="margin-left:11%;"><b>RAMEN_USE_EMBEDDED_COMPILER</b></p>

<p style="margin-left:17%;">See option
<b>--use-external-compiler</b>.</p>

<p style="margin-left:11%;"><b>RAMEN_VARIANTS</b></p>

<p style="margin-left:17%;">See option
<b>--variant</b>.</p>
<? include "footer.php" ?>
