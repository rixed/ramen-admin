<? include "header.php" ?>

<h1 align=center>ramen-run</h1>



<a name="NAME"></a>
<h2>NAME</h2>


<p style="margin-left:11%; margin-top: 1em">Ramen-run - Run
one (or several) compiled program(s)</p>

<a name="SYNOPSIS"></a>
<h2>SYNOPSIS</h2>


<p style="margin-left:11%; margin-top: 1em"><b>Ramen
run</b> [<i>OPTION</i>]... <i>FILE</i></p>

<a name="ARGUMENTS"></a>
<h2>ARGUMENTS</h2>


<p style="margin-left:11%; margin-top: 1em"><i>FILE</i>
(required)</p>

<p style="margin-left:17%;">Binary file to run</p>

<a name="OPTIONS"></a>
<h2>OPTIONS</h2>



<p style="margin-left:11%; margin-top: 1em"><b>--as</b>=<i>NAME</i></p>

<p style="margin-left:17%;">resulting program name</p>

<p style="margin-left:11%;"><b>--help</b>[=<i>FMT</i>]
(default=auto)</p>

<p style="margin-left:17%;">Show this help in format
<i>FMT</i>. The value <i>FMT</i> must be one of
&lsquo;auto', &lsquo;pager', &lsquo;groff' or &lsquo;plain'.
With &lsquo;auto', the format is &lsquo;pager&lsquo; or
&lsquo;plain' whenever the <b>TERM</b> env var is
&lsquo;dumb' or undefined.</p>

<p style="margin-left:11%;"><b>--kill-if-disabled</b></p>

<p style="margin-left:17%;">If the program is disabled by a
run-if clause then kills it instead</p>

<p style="margin-left:11%;"><b>-p</b> <i>PARAM=VALUE</i>,
<b>--parameter</b>=<i>PARAM=VALUE</i></p>

<p style="margin-left:17%;">Override parameter's P default
value with V</p>

<p style="margin-left:11%;"><b>-r</b>, <b>--replace</b></p>

<p style="margin-left:17%;">If a program with the same name
is already running, replace it</p>


<p style="margin-left:11%;"><b>--report-period</b>=<i>VAL</i>
(absent=30. or <b>RAMEN_REPORT_PERIOD</b> env)</p>

<p style="margin-left:17%;">Number of seconds between two
stats report from each worker</p>

<p style="margin-left:11%;"><b>--src-file</b>=<i>VAL</i>,
<b>--source-file</b>=<i>VAL</i></p>

<p style="margin-left:17%;">file from which the worker can
be rebuilt</p>

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
environment variables affect the execution of <b>run</b>:
<b><br>
RAMEN_DEBUG</b></p>

<p style="margin-left:17%;">See option <b>--debug</b>.</p>


<p style="margin-left:11%;"><b>RAMEN_INITIAL_EXPORT</b></p>

<p style="margin-left:17%;">See option
<b>--initial-export-duration</b>.</p>


<p style="margin-left:11%;"><b>RAMEN_KEEP_TEMP_FILES</b></p>

<p style="margin-left:17%;">See option
<b>--keep-temp-files</b>.</p>

<p style="margin-left:11%;"><b>RAMEN_PERSIST_DIR</b></p>

<p style="margin-left:17%;">See option
<b>--persist-dir</b>.</p>

<p style="margin-left:11%;"><b>RAMEN_QUIET</b></p>

<p style="margin-left:17%;">See option <b>--quiet</b>.</p>

<p style="margin-left:11%;"><b>RAMEN_RANDOM_SEED</b></p>

<p style="margin-left:17%;">See option <b>--seed</b>.</p>

<p style="margin-left:11%;"><b>RAMEN_REPORT_PERIOD</b></p>

<p style="margin-left:17%;">See option
<b>--report-period</b>.</p>

<p style="margin-left:11%;"><b>RAMEN_VARIANTS</b></p>

<p style="margin-left:17%;">See option
<b>--variant</b>.</p>
<? include "footer.php" ?>
