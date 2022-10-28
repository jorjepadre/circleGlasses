# Circle Glasses

Circle Glasses is an interactive openFrameworks application. 
The app uses the webcam as an input and implements Circle Detection to find the empty circles inside the glasses and fills them with eyes.

## Demo
![](https://github.com/jorjepadre/circleGlasses/blob/master/bin/data/demo.gif)

## Methodology
The main techniques used in the project are **Canny Edge Detection** and **Hough Gradient Method**. 
The project shows that these techniques can be used for interactive circle detection.

### Implementation
Firstly, we initiate a webcam grabber to get the input from the webcam realtime. Then, on update, I grab each frame and produce the matrix from the frame.
After that, I produce Gaussian Blur to remove noise and filter a matrix. This is followed by producing Canny Edge Detection.
This leaves us with a frame matrix showing all the edges for the given threshold. After that, I produce Hough Gradient Method to detec the circles on the frame.
Finally, it is only required to draw the 2 circles, one fill with white color which is outer part of an eye, and a smaller circle filled with black.
