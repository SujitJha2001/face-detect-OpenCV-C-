#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>
#include<iostream>

using namespace std;
using namespace cv;

//knowledge doctor
//advanced newbies
int main() {

	Mat image;

	namedWindow("Display window");

	VideoCapture cap(0);
	CascadeClassifier facedetect;
	Mat img;
	facedetect.load("haarcascade_frontalface_default.xml");


	if (!cap.isOpened()) {

		cout << "cannot open camera";

	}

	while (true) {

		cap >> image;

		vector<Rect> faces;

		facedetect.detectMultiScale(image, faces, 1.3, 5);

		cout << faces.size() << endl;

		for (int i = 0; i < faces.size(); i++) {
			rectangle(image, faces[i].tl(), faces[i].br(), Scalar(50, 50, 255), 3);
			rectangle(image, Point(0, 0), Point(250, 70), Scalar(50, 50, 255), FILLED);
			putText(image, to_string(faces.size()) + " Face Found", Point(10, 40), FONT_HERSHEY_DUPLEX, 1, Scalar(255, 255, 255), 1);
		}

		imshow("Display window", image);

		waitKey(1);

	}

	return 0;

}