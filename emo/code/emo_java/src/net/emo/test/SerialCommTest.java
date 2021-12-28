package net.emo.test;

import java.util.Scanner;

import net.emo.comm.SerialComm;

public class SerialCommTest {
	
	static SerialComm arduinoComm;
	
	public static void main(String[] args) throws Exception {	
		// TODO Auto-generated method stub
		System.out.println("emo Java");
		System.out.println("========");
		System.out.println();
		System.out.println("Serial communication with Arduino (RTXT)");
		
		arduinoComm = new SerialComm();
		arduinoComm.init();
		
		Scanner user_input = new Scanner(System.in);
	    String messageString = "";
		
		while (true) {
			// messageString =  user_input.next();
			messageString = "hello world\n";
			arduinoComm.message(messageString);
		}
	}
}
