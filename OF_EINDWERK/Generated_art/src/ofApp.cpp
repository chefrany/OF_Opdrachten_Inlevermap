#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	showGui = true; // laat de gui's zien
	gui.setup( "Parameters" , "settings.xml"); // maak de groep aan en vul deze 
	gui.add(countX.setup( "countX" , 50 ,0,200)); // aantal duplicaties object X 
	gui.add(stepX.setup("stepX" , 20, 0, 200)); //tussen ruimte  X
	gui.add ( twistX.setup ( "twistX", 5 , -45 , 45)); // de hoek waarmee ze draaien X 
	
    gui.add( countY.setup( "countY", 0, 0, 50) ); // aantal duplicaties Y
    gui.add( stepY.setup( "stepY", 20, 0, 200 ) ); // tussenruimte in de Y
    gui.add( twistY.setup( "twistY", 0, -30, 30 ) ); // de twist in de Y
    gui.add( pinchY.setup( "pinchY", 0, 0, 1 ) ); //  hoe schuin het object staat	

	globalGroup.setup("Global" , "settings.xml"); // maak de groep aan en vul deze 
	globalGroup.add(musicSpeed.setup("MusicSpeed",0.9 , 0,01 , 2.0) );
	globalGroup.add(Scale.setup("Scale" , 1 , 0.0 , 1 )); // Camera afstand 
	globalGroup.add(Rotate.setup("Rotate" , 0 , -180 , 180 )); // Rotatie van de complete matrix 
	globalGroup.add(Background.setup("background" , ofColor::black, ofColor(0,0,0) , ofColor::white )); // R,G,B
	

	primGroup.setup("primitive" , "settings.xml");
	primGroup.add(shiftY.setup("shiftY" ,0.0 , -1000.0 , 1000.0)); 
	primGroup.add(rotate.setup("rotate" , 0.0 , -180.0 , 180.0)); // rotatie van de objecten
	primGroup.add(size.setup( "size" , ofVec2f(6,6) , ofVec2f (0,0) , ofVec2f(20,20) )); // x,y  = 2f || de grote van het object  
	primGroup.add(lineWidth.setup("lineWidth", 0.5 , 0.0 , 7,0)); // De lijn dikte van het object 
	primGroup.add(color.setup("color" , ofColor::black, ofColor(0,0,0,0) , ofColor::white )); // 0 tot 255 in r,g,b,a
	primGroup.add(filled.setup("filled" , false )); //  line of fill
	primGroup.add(type.setup("type" , false )); // triangle of rect 
	
	gui.add(&primGroup);  // voeg primGroup aan deze gui toe 
	gui.add(&globalGroup); // voeg globalGroup aan deze gui toe

	gui.loadFromFile("settings.xml"); // haal de settings op van de settings.xml || alle gui's
	//globalGroup.loadFromFile("settings.xml");
	//primGroup.loadFromFile("settings.xml");

    ofSetWindowTitle("Generative_art");  // Naam van de applicatie
	ofSetWindowShape(1280 , 720);        // formaat van je progamma 
	ofSetFullscreen(true);               // schermvullend zonder border
	ofSetFrameRate(60);                  // fps van je programma "60hz"
	serial.setup(0,9600);                // serial port 0  || speed 9600

	music.loadSound("Vacant_Silent.wav"); // nummer 
	music.setLoop(true);                  // start opnieuw indien afgelopen 
	music.setVolume(1);                   // volume van het fragment 
	//music.setSpeed(0.9f);                 // afspeel snleheid 
	music.play();                         // speel hem af 
	music.setPaused(true);                // zet het numer op pauze aan het begin van het nummer 
	ofSoundSetVolume(0.5);                // overal volume van OF
	
}

//--------------------------------------------------------------
void ofApp::update(){
	/*   Arduino gedeelte  
	Werkt prima */
while ( true ) {
int c = serial.readByte();
if ( c == OF_SERIAL_NO_DATA || c == OF_SERIAL_ERROR || c == 0 )
break;
if ( c == '\n' ) {
vector<string> list = ofSplitString( str, " " ); // splitst elke waarde door de spatie 
if ( list.size() >= 6 ) {          // geef hier de grote aan van de list 
Scale = ofToFloat( list    [0] );     // A0  
musicSpeed = ofToFloat( list[1] );    // A1
pinchY = ofToFloat( list[2] );        // A2
lineWidth = ofToFloat( list[3] )*7;   // A3
countY = ofToFloat( list[4] )*50;     // A4
countX = ofToFloat( list[5] )*200;    // A5

}
str = "";
}
else str.push_back( c );
}

music.setSpeed(musicSpeed);                 // afspeel snleheid 
}
//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground( Background); // white black slider
	
	ofPushMatrix();        //verschuif de current cordinaten 
	ofTranslate(ofGetWidth()/2 , ofGetHeight()/2); // verschuift het (0x,0y) punt naar net midden van het scherm 
	// --> code here
	float Scl = pow(Scale, 4.0f); // macht 4  om kleinere veranderingen te kunnen maken
	ofScale (Scl,Scl);
	ofRotate(Rotate);  // de rotatie van de objecten
    //stripePattern();
	matrixPattern();
	// <-- code here 
	ofPopMatrix(); // zet de cordinaten weer terug op zijn orginele positie "links boven"
	if (showGui) gui.draw();            // zorgt er voor dat de gui's zichtbaar worden
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if ( key == 'g' ) showGui = !showGui; // druk op g en gui gaat uit beeld || true to false & false to true 
	if (key == OF_KEY_RETURN) ofSaveScreen ("GenerativeArtScreenshot" + ofToString(ofRandom(0,1000),0)+ ".png") ;
	/* druk op Enter voor screenshot || met random naam */

	if (key=='p') // afspelen of pauseren 
	{
		musicPaused = !musicPaused;
		music.setPaused(musicPaused);
	}

	if (key=='1')   // De verschillende key points binen het muziek fragment 
	{
		music.setPosition(0.0f); // begin 
	} else if (key=='2')
	{
		music.setPosition(0.2f); // 20% van het nummer 
	} else if (key=='3')
	{
		music.setPosition(0.4f); // 40% van het nummer 
	} else if (key=='4')
	{
		music.setPosition(0.6f); // 60% van het nummer 
	}else if (key=='5')
	{
		music.setPosition(0.8f); // 80% van het nummer 
	}


}

//--------------------------------------------------------------
void ofApp::exit(){
	gui.saveToFile("settings.xml");
	                                /* voor het sluiten van het 
	                                progamma worden de gegevens opgeslagen 
									van de gui's in de setting.xml 
									Deze staat in de bin/data folder */

}
//--------------------------------------------------------------
/* wordt gebruikt in matrixPattern*/
void ofApp::stripePattern() {
	


ofSetColor( color); // ofxColorSlider

ofSetLineWidth(lineWidth); // LijnDikte 
if (filled) ofFill(); else ofNoFill(); // ofxToggle -- checked or unchecked 
for (int i=-countX; i<countX; i++) { 
ofPushMatrix();            // begin 
ofTranslate( i*stepX, 0 );    // verschuift de cordinaten bij elke loop 
ofRotate (i*twistX);// veranderd de rotatie voor elke loop 

ofTranslate(0,shiftY);
ofRotate(rotate);
ofScale( size ->x , size ->y);  // aangeven welke x en welke y moet zijn van de ofxVex2Slider
if (type) ofRect(-50 , -50 , 100,100); 
else ofTriangle( 0, 0, -50, 100, 50, 100 );  
ofPopMatrix();             // eind 
 }
}
//--------------------------------------------------------------

void ofApp::matrixPattern() {
for (int y=-countY; y<=countY; y++) {
ofPushMatrix();
//---------------------
if ( countY > 0 ) {
float scl = ofMap( y, -countY, countY, 1-pinchY, 1 );
ofScale( scl, scl );
}
ofTranslate( 0, y * stepY );
ofRotate( y * twistY );
stripePattern();
//---------------------
ofPopMatrix();
}
}