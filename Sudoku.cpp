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


void imageCroptop(const Mat& img, vector<vector<Mat>>& imageVec) {

	//parameters are the original picture with lines removed
	//and an empty 2D vector of images


	//there will be a total of 81 cells which contain eitehr
	//a blank or a single digit

	int RowCellSize = img.rows/9;
	int ColCellSize = img.cols/9; 
	int x1 = 0, x2 = RowCellSize, y1 = 0, y2 = ColCellSize;

	vector<Mat> newVec1;
	for (int i = 0; i < 9; i++) {
		Rect crop(x1, y1, x2, y2);
		Mat croppedImage = img(crop);
		newVec1.push_back(croppedImage);
		x1 += RowCellSize;
	}

	x1 = 0;
	y1 += ColCellSize;
	vector<Mat> newVec2;
	for (int i = 0; i < 9; i++) {
		Rect crop(x1, y1, x2, y2);
		Mat croppedImage = img(crop);
		newVec2.push_back(croppedImage);
		x1 += RowCellSize;
	}

	x1 = 0;
	y1 += ColCellSize;
	vector<Mat> newVec3;
	for (int i = 0; i < 9; i++) {
		Rect crop(x1, y1, x2, y2);
		Mat croppedImage = img(crop);
		newVec2.push_back(croppedImage);
		x1 += RowCellSize;
	}

	x1 = 0;
	y1 += ColCellSize;
	vector<Mat> newVec4;
	for (int i = 0; i < 9; i++) {
		Rect crop(x1, y1, x2, y2);
		Mat croppedImage = img(crop);
		newVec2.push_back(croppedImage);
		x1 += RowCellSize;
	}

	x1 = 0;
	y1 += ColCellSize;
	vector<Mat> newVec5;
	for (int i = 0; i < 9; i++) {
		Rect crop(x1, y1, x2, y2);
		Mat croppedImage = img(crop);
		newVec2.push_back(croppedImage);
		x1 += RowCellSize;
	}

	x1 = 0;
	y1 += ColCellSize;
	vector<Mat> newVec6;
	for (int i = 0; i < 9; i++) {
		Rect crop(x1, y1, x2, y2);
		Mat croppedImage = img(crop);
		newVec2.push_back(croppedImage);
		x1 += RowCellSize;
	}

	x1 = 0;
	y1 += ColCellSize;
	vector<Mat> newVec7;
	for (int i = 0; i < 9; i++) {
		Rect crop(x1, y1, x2, y2);
		Mat croppedImage = img(crop);
		newVec2.push_back(croppedImage);
		x1 += RowCellSize;
	}

	x1 = 0;
	y1 += ColCellSize;
	vector<Mat> newVec8;
	for (int i = 0; i < 9; i++) {
		Rect crop(x1, y1, x2, y2);
		Mat croppedImage = img(crop);
		newVec2.push_back(croppedImage);
		x1 += RowCellSize;
	}

	x1 = 0;
	y1 += ColCellSize;
	vector<Mat> newVec9;
	for (int i = 0; i < 9; i++) {
		Rect crop(x1, y1, x2, y2);
		Mat croppedImage = img(crop);
		newVec2.push_back(croppedImage);
		x1 += RowCellSize;
	}

	imageVec.push_back(newVec1);
	imageVec.push_back(newVec2);
	imageVec.push_back(newVec3);
	imageVec.push_back(newVec4);
	imageVec.push_back(newVec5);
	imageVec.push_back(newVec6);
	imageVec.push_back(newVec7);
	imageVec.push_back(newVec8);
	imageVec.push_back(newVec9);
}


void vectorPrint(vector<vector<Mat>>& imageVec) {
	cout << imageVec.size() << endl;
	if (imageVec.size()) {
		cout << imageVec[0].size() << endl;
	}

	for (vector<Mat> Row : imageVec) {
		for (Mat col : Row) {
			imwrite("TestImage.jpg", col);
			//imshow("Display window", col);
			//waitKey(0);
		}
	}


	/*
	for (int i = 0; i < imageVec.size(); i++) {
		for (int j = 0; j < imageVec[0].size(); j++) {
			namedWindow("uhh", WINDOW_AUTOSIZE);
			imshow("Display window", imageVec[i][j]);
			waitKey(0);
		}
	}
	
	
	
	*/
	
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

	/*
	OCR can't read entire pages of scattered numbers without fliiping out
	so the next best option is to spilt each grid into it's own image
	and read it using the -psm flag and store into the 2D vector.

	First start by parse the image into a 2D vector of images.
	Might not be legal but.
	*/

	vector<vector<Mat>> imageVector;
	imageCroptop(newImage, imageVector);
	vectorPrint(imageVector);
	//imwrite("TestImage.jpg", newImage);

	//the image has been cropped into 81 different images
	//now use the TesOCR library to read each image into a 2D vector
	//and from there make an algroithm that solves the vector
	//OCR can only read images so the Mat files must be turned
	//from Mat -> jgg/tiff -> read and stored -> deleted

	return 0;
}
