#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;

void invertImage(Mat& img) {

	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			int rgbSum = int(img.at<cv::Vec3b>(i, j)[0]) + int(img.at<cv::Vec3b>(i, j)[1]) + int(img.at<cv::Vec3b>(i, j)[2]);
			if (rgbSum == 0) {
				img.at<cv::Vec3b>(i, j)[0] = 255;
				img.at<cv::Vec3b>(i, j)[1] = 255;
				img.at<cv::Vec3b>(i, j)[2] = 255;
			}
			else {
				img.at<cv::Vec3b>(i, j)[0] = 0;
				img.at<cv::Vec3b>(i, j)[1] = 0;
				img.at<cv::Vec3b>(i, j)[2] = 0;
			}
			
		}

	}

}

Mat isline(const Mat img) {
	Mat newImage = img.clone();
	
	int blackTotalRow = 0 * 3 * img.cols;
	for (int i = 0; i < img.cols; i++) {
		int rowTotal = 0;
		for (int j = 0; j < img.rows; j++) {
			int rgbSum = int(img.at<cv::Vec3b>(i, j)[0]) + int(img.at<cv::Vec3b>(i, j)[1]) + int(img.at<cv::Vec3b>(i, j)[2]);
			rowTotal += rgbSum;
		}

		if (blackTotalRow == rowTotal) {
			for (int j = 0; j < img.rows; j++) {
				newImage.at<cv::Vec3b>(i, j)[0] = 255;
				newImage.at<cv::Vec3b>(i, j)[1] = 255;
				newImage.at<cv::Vec3b>(i, j)[2] = 255;
			}
		}
	}

	int blackTotalCol = 0 * 3 * img.rows;
	for (int j = 0; j < img.rows; j++) {
		int colTotal = 0;
		for (int i = 0; i < img.cols; i++) {
			int rgbSum = int(img.at<cv::Vec3b>(i, j)[0]) + int(img.at<cv::Vec3b>(i, j)[1]) + int(img.at<cv::Vec3b>(i, j)[2]);
			colTotal += rgbSum;
		}
		if (blackTotalCol == colTotal) {
			for (int i = 0; i < img.cols; i++) {
				newImage.at<cv::Vec3b>(i, j)[0] = 255;
				newImage.at<cv::Vec3b>(i, j)[1] = 255;
				newImage.at<cv::Vec3b>(i, j)[2] = 255;
			}
		}
	}

	return newImage;
}


int main(int argc, char** argv)
{
	string picName = "in.png";
	cv::Mat img = cv::imread(picName);

	if (img.empty())
	{
		cout << "Could not open or find the image" << endl;
		cin.get(); 
		return -1;
	}

	invertImage(img);
	invertImage(img);
	Mat newImage = isline(img);



				
	//creates new Mat object and makes in gray
	//Mat grayTest;
	//cvtColor(img, grayTest, CV_BGR2GRAY);

	imwrite("TestImage.jpg", newImage);


	/*

	namedWindow("newOne", CV_WINDOW_AUTOSIZE);
	imshow("newOne", newImage);
	waitKey(0);

	int count = 0;
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			int rgbSum = int(img.at<cv::Vec3b>(i, j)[0]) + int(img.at<cv::Vec3b>(i, j)[1]) + int(img.at<cv::Vec3b>(i, j)[2]);

		}
	}


	namedWindow(picName, CV_WINDOW_AUTOSIZE);
	namedWindow("Gray image", CV_WINDOW_AUTOSIZE);

	imshow(picName, img);
	imshow("Gray image", grayTest);


	String windowName = "NewWindow"; //Name of the window
	namedWindow(windowName); // Create a window
	imshow(windowName, image); // Show our image inside the created window.
	waitKey(0); // Wait for any keystroke in the window
	destroyWindow(windowName); //destroy the created window
	*/
	//waitKey(0);

	return 0;
}