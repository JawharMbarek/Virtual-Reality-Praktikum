/**
 * gui.cpp
 * TODO
 *
 * Created: 2017-09-02
 * Author: Aykut Özdemir
 */

#include "../../Header/GUI/gui.h"
#include "../../Header/GUI/cvui.h"

/**
  *
  */
void initializeGUI(const cv::String &windowName, Application &app)
{
    cvui::init(windowName, -1);
    app.minContourPointsAllowed = 50;
    app.minSideEdgeLength = 5000;
    app.validMarkerCount = 0;
}

void GUI(cv::Mat &frame, Application &app, int fps)
{
    // Main GUI frame
    cvui::window(frame, 0, 0, 180, frame.cols, "Settings");
    cvui::beginColumn(frame, 5, 30, -1, -1, 5);
    cvui::text(std::to_string(fps) + " fps");

    // Min contour points allowed
    cvui::text("Min contour points allowed");
    cvui::trackbar(150, &app.minContourPointsAllowed, 1, 300);
    cvui::space(5);

    // Min side edge length
    cvui::text("Min side edge length");
    cvui::trackbar(150, &app.minSideEdgeLength, 1000, 30000);
    cvui::space(5);

    // Valid marker count
    cvui::text("Found valid marker: " + std::to_string(app.validMarkerCount));
    cvui::space(5);
    cvui::endColumn();

    cvui::update();
}