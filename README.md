# Resizer item

`GraphicsItemResizer` is a `QGraphicsItem` for interactive resizing of some target rectangular
area (for example, to change size and position of some `QGraphicsItem`, as in demo project).
It shows 8 handles within container item for each resizing direction and supports
minimum size constraint for target rect (i.e. you can't make size of target rect
smaller than specified).

### How to use it
Copy `resizer` dir to your project. Include file `resizer/graphicsitemresizer.h`.
Create instance of `GraphicsItemResizer` class, set target rectangle value to your
initial rectangle bounds (position will be ignored) and minimum size if needed.

To handle size and position changes subscribe to `GraphicsItemResizer::targetRectChanged`
signal.

You can change pen and brush for resizer handles using `setPen` and `setBrush`
methods.

### License
Resizer item is licensed under the Apache License, Version 2.0. See LICENSE for details.
