All objects specific to timelines
=================================

Time lines are graphical representation of some time range.

- AbstractTimeLine: a scrollable QWidget used to represent a chart in a given time
  range.

- HeatLine: an AbstractTimeLine that displays colored blocks.

- BinaryHeatLine: a black&white HeatLine

- TimeLine: an AbstractTimeLine that displays a time axis

- TimeLineGroup: connect together a set of AbstractTimeLine objects so that
  they scroll together.

- TimeLineView: a widget that displays an AbstractTimeLine for every defined
  function, with a TimeLine ruler on top and at the bottom.


