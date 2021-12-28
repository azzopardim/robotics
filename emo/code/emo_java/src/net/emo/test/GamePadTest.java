package net.emo.test;

import net.emo.control.Gamepad;

public class GamePadTest {

	public static void main(String[] args) {
		System.out.println("emo Java");
		System.out.println("========");
		System.out.println();
		System.out.println("Gamepad control");
		
		Gamepad gamepad = new Gamepad();
	
		gamepad.initialize();
		
		// X axis and Y axis
        int xAxisPercentage = 0;
        int yAxisPercentage = 0;
        
		System.out.println("Started");
		
		while (true) {
			// System.out.println(gamepad.getYAxisValue());
			int xAxisValueInPercentage = gamepad.getAxisValueInPercentage(gamepad.getXAxisValue());
            int yAxisValueInPercentage = gamepad.getAxisValueInPercentage(gamepad.getYAxisValue());
            System.out.println(xAxisValueInPercentage+","+yAxisValueInPercentage);
            gamepad.update();
		}
	}
	
}
