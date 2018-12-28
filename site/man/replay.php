<? include "header.php" ?>

<h1 align=center>ramen-replay</h1>



<a name="NAME"></a>
<h2>NAME</h2>


<p style="margin-left:11%; margin-top: 1em">Ramen-replay -
Rebuild the past output of the given operation</p>

<a name="SYNOPSIS"></a>
<h2>SYNOPSIS</h2>


<p style="margin-left:11%; margin-top: 1em"><b>Ramen
replay</b> [<i>OPTION</i>]... <i>OPERATION</i>...</p>

<a name="ARGUMENTS"></a>
<h2>ARGUMENTS</h2>



<p style="margin-left:11%; margin-top: 1em"><i>OPERATION</i>
(required)</p>

<p style="margin-left:17%;">function fully qualified name
and field names, or code statement</p>

<a name="OPTIONS"></a>
<h2>OPTIONS</h2>



<p style="margin-left:11%; margin-top: 1em"><b>--bundle-dir</b>=<i>VAL</i>
(absent=/usr/lib/ramen/bundle/ or <b>RAMEN_LIBS</b> env)</p>

<p style="margin-left:17%;">Directory where to find
libraries for the embedded compiler</p>

<p style="margin-left:11%;"><b>--flush</b></p>

<p style="margin-left:17%;">Flush each line to stdout</p>

<p style="margin-left:11%;"><b>-h</b> [<i>VAL</i>],
<b>--with-header</b>[=<i>VAL</i>],
<b>--header</b>[=<i>VAL</i>] <br>
(default=4611686018427387903) (absent=0)</p>

<p style="margin-left:17%;">Output the header line in
CSV</p>

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

<p style="margin-left:11%;"><b>--null</b>=<i>VAL</i>
(absent=&lt;NULL&gt; or <b>RAMEN_CSV_NULL</b> env)</p>

<p style="margin-left:17%;">Representation of NULL
values</p>

<p style="margin-left:11%;"><b>--pretty</b></p>

<p style="margin-left:17%;">Prettier output</p>

<p style="margin-left:11%;"><b>--raw</b></p>

<p style="margin-left:17%;">Do not quote values</p>

<p style="margin-left:11%;"><b>--separator</b>=<i>VAL</i>
(absent=, or <b>RAMEN_CSV_SEPARATOR</b> env)</p>

<p style="margin-left:17%;">Field separator</p>

<p style="margin-left:11%;"><b>--since</b>=<i>SINCE</i>
(required)</p>

<p style="margin-left:17%;">Timestamp of the first
point</p>

<p style="margin-left:11%;"><b>--solver</b>=<i>VAL</i>,
<b>--smt-solver</b>=<i>VAL</i> (absent=z3 -t:20000 -smt2 %s
or <b><br>
RAMEN_SMT_SOLVER</b> env)</p>

<p style="margin-left:17%;">Command to run the SMT solver
(with %s in place of the SMT2 file name)</p>

<p style="margin-left:11%;"><b>-t</b>, <b>--with-times</b>,
<b>--with-event-times</b>, <b>--event-times</b></p>

<p style="margin-left:17%;">Prepend tuples with their event
time</p>

<p style="margin-left:11%;"><b>-u</b>, <b>--with-units</b>,
<b>--units</b></p>

<p style="margin-left:17%;">Add units in the header
line</p>

<p style="margin-left:11%;"><b>--until</b>=<i>UNTIL</i>
(required)</p>

<p style="margin-left:17%;">Timestamp of the last point</p>


<p style="margin-left:11%;"><b>--use-external-compiler</b>,
<b>--external-compiler</b> (absent <b><br>
RAMEN_USE_EMBEDDED_COMPILER</b> env)</p>

<p style="margin-left:17%;">Call external compiler rather
than using embedded one</p>

<p style="margin-left:11%;"><b>--version</b></p>

<p style="margin-left:17%;">Show version information.</p>

<p style="margin-left:11%;"><b>-w</b> <i>FIELD=VALUE</i>,
<b>--where</b>=<i>FIELD=VALUE</i></p>

<p style="margin-left:17%;">Output only tuples which given
field match the given value</p>

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
(absent=/tmp/ramen or <b>RAMEN_DIR</b> env)</p>

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
environment variables affect the execution of <b>replay</b>:
<b><br>
RAMEN_CSV_NULL</b></p>

<p style="margin-left:17%;">See option <b>--null</b>.</p>

<p style="margin-left:11%;"><b>RAMEN_CSV_SEPARATOR</b></p>

<p style="margin-left:17%;">See option
<b>--separator</b>.</p>

<p style="margin-left:11%;"><b>RAMEN_DEBUG</b></p>

<p style="margin-left:17%;">See option <b>--debug</b>.</p>

<p style="margin-left:11%;"><b>RAMEN_DIR</b></p>

<p style="margin-left:17%;">See option
<b>--persist-dir</b>.</p>


<p style="margin-left:11%;"><b>RAMEN_INITIAL_EXPORT</b></p>

<p style="margin-left:17%;">See option
<b>--initial-export-duration</b>.</p>


<p style="margin-left:11%;"><b>RAMEN_KEEP_TEMP_FILES</b></p>

<p style="margin-left:17%;">See option
<b>--keep-temp-files</b>.</p>

<p style="margin-left:11%;"><b>RAMEN_LIBS</b></p>

<p style="margin-left:17%;">See option
<b>--bundle-dir</b>.</p>


<p style="margin-left:11%;"><b>RAMEN_MAX_SIMULT_COMPILATIONS</b></p>

<p style="margin-left:17%;">See option
<b>--max-simult-compilations</b>.</p>

<p style="margin-left:11%;"><b>RAMEN_QUIET</b></p>

<p style="margin-left:17%;">See option <b>--quiet</b>.</p>

<p style="margin-left:11%;"><b>RAMEN_RANDOM_SEED</b></p>

<p style="margin-left:17%;">See option <b>--seed</b>.</p>

<p style="margin-left:11%;"><b>RAMEN_SMT_SOLVER</b></p>

<p style="margin-left:17%;">See option
<b>--smt-solver</b>.</p>


<p style="margin-left:11%;"><b>RAMEN_USE_EMBEDDED_COMPILER</b></p>

<p style="margin-left:17%;">See option
<b>--use-external-compiler</b>.</p>

<p style="margin-left:11%;"><b>RAMEN_VARIANTS</b></p>

<p style="margin-left:17%;">See option
<b>--variant</b>.</p>
<? include "footer.php" ?>
