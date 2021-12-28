package net.emo.test;

import gnu.io.SerialPortEvent;
import gnu.io.SerialPortEventListener;

import java.util.ArrayList;

import net.emo.comm.SerialComm;
import net.emo.control.Gamepad;
import net.java.games.input.Component;
import net.java.games.input.Component.Identifier;
import net.java.games.input.Controller;
import net.java.games.input.ControllerEnvironment;

public class PanTiltGamepad {
	final static Gamepad gamepad = new Gamepad();
	static SerialComm arduinoComm = new SerialComm();
	
	public static void main(String[] args) {
		System.out.println("emo Java");
		System.out.println("========");
		System.out.println();
		
		System.out.println("Gamepad control");
		gamepad.initialize();
		
		// X axis and Y axis
        int xAxisPercentage = 0;
        int yAxisPercentage = 0;
		
		System.out.println("Serial communication with Arduino (RTXT)");
	    arduinoComm = new SerialComm();
		arduinoComm.init();

		Thread t=new Thread() {
			public void run() {
				//the following line will keep this app alive for 1000 seconds,
				//waiting for events to occur and responding to them (printing incoming messages to console).
				try {
					
					while (true) {
						gamepad.update();
						
						// System.out.println(gamepad.getYAxisValue());
						int xAxisValueInPercentage = gamepad.getAxisValueInPercentage(gamepad.getXAxisValue());
			            int yAxisValueInPercentage = gamepad.getAxisValueInPercentage(gamepad.getYAxisValue());
			           
			            // Send messages 
			            char c = 'n';
			            //System.out.println(xAxisValueInPercentage+", "+yAxisValueInPercentage);
			            if (xAxisValueInPercentage >= 80) {
			            	//System.out.println("pan right");
			            	// pan right
			            	c ='r';
			            }  
			            if (xAxisValueInPercentage <= 20) {
			            	//System.out.println("pan left");
			            	// pan left
			            	c = 'l';
			            } 
			            if (yAxisValueInPercentage >= 80) {
			            	//System.out.println("tilt down");
			            	// tilt up
			            	c = 'd';
			            } 
			            if (yAxisValueInPercentage <= 20) {
			            	//System.out.println("tilt up");
			            	// tilt down
			            	c = 'u';
			            }
			            
			            if ((xAxisValueInPercentage < 80) && (xAxisValueInPercentage > 20) && (yAxisValueInPercentage < 80) && (yAxisValueInPercentage > 20)) {
			            	arduinoComm.message('n');
			            } 
			            
			            System.out.println("Sending message "+c);
			            
			            arduinoComm.message(c);
  
			            Thread.sleep(1000);
			            
			            //TODO: need to change this implementation and have the 100% axis value sent and that translated to 100% angle
			            // ***********************************************************************************************************
			            // Sending individual commands is not relative to the motion as the number of signals read is going to be dependent on the clock cycle
			            // An approach would be to have a speed of reading synced to the speed to motion but that would potentially case a delay
			            // So now I need to find how I send a decimal value through the Serial port
			            
			            
					}
				} catch (Exception ie) {}
			}
		};
		t.start();
		
		System.out.println("Started");
		
	}

}
