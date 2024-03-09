#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openframeworks");
	
	ofBackground(39);
	ofSetLineWidth(1);
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	ofColor color;
	for (int radius = 200; radius >= 50; radius -= 50) {

		for (int i = 0; i < 6; i++) {

			float left_deg_start = ofGetFrameNum() * 5 - i * 15 + ofMap(radius, 50, 200, 0, 270);
			float right_deg_start = ofGetFrameNum() * 5 - i * 15 + ofMap(radius, 50, 200, 0, 270);

			vector<glm::vec2> vertices;
			for (float deg = left_deg_start; deg < left_deg_start + 10; deg += 1) {

				vertices.push_back(glm::vec2(-180 + radius * cos(deg * DEG_TO_RAD), -180 + radius * sin(deg * DEG_TO_RAD)));
			}

			for (float deg = right_deg_start; deg > right_deg_start - 10; deg -= 1) {

				vertices.push_back(glm::vec2(180 + radius * cos(deg * DEG_TO_RAD), 180 + radius * sin(deg * DEG_TO_RAD)));
			}

			color.setHsb(ofMap(i, 0, 6, 0, 255), 200, 255);

			ofFill();
			ofSetColor(color, 200);

			ofBeginShape();
			ofVertices(vertices);
			ofEndShape(true);

			ofNoFill();
			ofSetColor(255);

			ofBeginShape();
			ofVertices(vertices);
			ofEndShape(true);
		}
	}

	/*
	int start = 250;
	if (ofGetFrameNum() > start) {

		ostringstream os;
		os << setw(4) << setfill('0') << ofGetFrameNum() - start;
		ofImage image;
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.saveImage("image/cap/img_" + os.str() + ".jpg");
		if (ofGetFrameNum() - start >= 25 * 20) {

			std::exit(1);
		}
	}
	*/
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}