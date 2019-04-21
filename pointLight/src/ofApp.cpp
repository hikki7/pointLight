#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // initial setting
    ofSetFrameRate(60);
    ofSetBackgroundColor(0);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    
    // shader setings
    shader.load("shaders/shader");
    
    // camera setting
    easyCam.setNearClip(0);
    easyCam.setFarClip(1500);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
    
    time = ofGetElapsedTimef();
}

//--------------------------------------------------------------
void ofApp::draw(){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    easyCam.begin();
    
    shader.begin();
    
    for(int i=0; i<MODEL_NUM; i++){
        
        // model Matrix
        ofMatrix4x4 modelMatrix;
        if(i == 0) modelMatrix.translate(-200, 0, 0);
        if(i == 1) modelMatrix.translate(0, 200, 0);
        if(i == 2) modelMatrix.translate(200, 0, 0);
        
        modelMatrix.rotate(time*10, 1.0, 0.5, 0.0);
        
        // view Matrix
        ofMatrix4x4 viewMatrix;
        viewMatrix = ofGetCurrentViewMatrix();
        
        // projection Matrix
        ofMatrix4x4 projectionMatrix;
        projectionMatrix = easyCam.getProjectionMatrix();
        
        // mvp Matrix
        ofMatrix4x4 mvpMatrix;
        mvpMatrix = modelMatrix * viewMatrix * projectionMatrix;
        
        // inv Matrix
        ofMatrix4x4 invMatrix;
        invMatrix = modelMatrix.getInverse();
        
        // light position
        vec3 lightPosition = vec3(0.0, 0.0, 0.0);
        
        // eyeDirection
        vec3 eyeDirection = vec3(easyCam.getPosition());
        
        // ambient Color
        vec4 ambientColor = vec4(0.1, 0.1, 0.1, 1.0);
        
        shader.setUniformMatrix4f("model", modelMatrix);
        shader.setUniformMatrix4f("view", viewMatrix);
        shader.setUniformMatrix4f("projection", projectionMatrix);
        shader.setUniformMatrix4f("mvp", mvpMatrix);
        shader.setUniformMatrix4f("inv", invMatrix);
        shader.setUniform3f("lightPosition", lightPosition);
        shader.setUniform3f("eye", eyeDirection);
        shader.setUniform4f("ambientColor",ambientColor);
        
        vboMesh = sphere.getMesh();
        for(int j=0; j<vboMesh.getVertices().size(); j++){
            vboMesh.addColor(ofFloatColor(1.0,1.0,1.0,1.0));
        }
        vboMesh.setMode(OF_PRIMITIVE_TRIANGLES);
        vboMesh.draw();
    }
    
    shader.end();
    
    easyCam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
