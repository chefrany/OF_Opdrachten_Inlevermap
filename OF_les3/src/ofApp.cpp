#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
	gui.setup("instellingen","setting.xml");

	gui.add(speedX.setup("speedX",1,0,50));
	gui.add(speedY.setup("speedY",1,0,50));
    
    gui.loadFromFile("settings.xml");

	hoeveelheid = 1; 
	hoeveelheid2 = hoeveelheid*2;
	hoeveelheid3 = hoeveelheid*3;

	addONE = 0;
	
	color_Grey.set(150);

	for (int i=0; i<hoeveelheid; i++) {
		 blub newBall;
		 newBall.begin();
		 fluffy.push_back(newBall);
    }

	for (int i=0; i<hoeveelheid2; i++) {
		 kaas newBall(speedY,speedX);
		 newBall.begin(speedX);
		 swoopy.push_back(newBall);
    }


	for (int i=0; i<hoeveelheid3; i++) {
		 vis newBall;
		 newBall.begin();
		 flapper.push_back(newBall);
    }
}

//--------------------------------------------------------------
void ofApp::update(){

	for (int i=0; i<fluffy.size(); i++) {
		fluffy[i].checken();	
   }

	for (int i=0; i<swoopy.size(); i++) {
	    swoopy[i].checken();	
   }

	for (int i=0; i<hoeveelheid3; i++) {
		flapper[i].checken();	
   }
}

//--------------------------------------------------------------
void ofApp::draw(){

	gui.draw();

	for (int i=0; i<fluffy.size(); i++) {
			fluffy[i].tekenen();	
   }

	for (int i=0; i<swoopy.size(); i++) {
			swoopy[i].tekenen();	
   }

	for (int i=0; i<hoeveelheid3; i++) {
		flapper[i].tekenen();	
   }

  
}
//-------------------------------------------------------------



//--------------------------------------------------------------
void ofApp::keyPressed(int key){



}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	 cout << "keyPressed " << key << endl;
	 
	if (key == 32){
		
	

		 kaas newBall(speedY,speedX);
		 newBall.begin(speedX);
		 swoopy.push_back(newBall);
		
		
		addONE += 1; 

		for(int i = 0; i < addONE; i++)
		{
	     blub newBall;
		 newBall.begin();
		 fluffy.push_back(newBall);
		 addONE = 0;
		}
} else if (key == 100){

	if(fluffy.size())
	{
		fluffy.erase(fluffy.begin());
		
	}

	if(swoopy.size())
	
		swoopy.erase(swoopy.begin());
	}


}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
