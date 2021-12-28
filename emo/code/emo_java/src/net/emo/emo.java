package net.emo;

import java.util.Scanner;

import net.emo.comm.Command;
import net.emo.comm.JsonCommands;
import net.emo.control.Gamepad;
import hcm.HardwareControlModule;
import java.lang.*;

public class emo {
	static State state;
	static HardwareControlModule hcm;
	static boolean run = false;
	private static int drive_prev = 0;
	
	public static void main(String[] args) {
		System.out.println("emo Java");
		prompt("Welcome!");

		// Initialization
		state = new State();
		state.setMode(State.AUTONOMOUS);

		prompt("Initializing Hardware Control Module");
		hcm = new HardwareControlModule();
		run = true;
		hcm.init();

		prompt("Initializing gamepad control");
		Gamepad gamepad = new Gamepad();

		gamepad.initialize();

		// Setup a keyboard scanner for user input
		Thread inputThread = new Thread(new Runnable() {
			@Override
			public void run() {
				prompt("Initializing user input in console");
				Scanner scan = new Scanner(System.in);
				String user_input = "";
				while (run == true) {
					System.out.print("[emo] > ");
					user_input = scan.nextLine();
					if (user_input != null) {
						if (user_input.contentEquals("q")) {
							run = false;
						} else if (user_input.contentEquals("a")) {
							// Set to autonomouos mode
							state.setMode(State.AUTONOMOUS);
							prompt("Emo is now in Autonomous mode");
							// TODO: Send command to set HCM
						} else if (user_input.contentEquals("r")) {
							// Set to remote mode
							prompt("This mode is currently not implemented.");
						} else if (user_input.contentEquals("m")) {
							// Set to manual mode
							state.setMode(State.MANUAL);
							prompt("Emo is now in Manual mode");
							// TODO: Send command to set HCM
						} else if (user_input.contentEquals("?")) {
							prompt("These are the valid commands");
							System.out.println("   Console");
							System.out.println("      q - quit");
							System.out.println();
							System.out.println("   Change mode");
							System.out.println("      a - autonomous");
							System.out.println("      r - remote");
							System.out.println("      m - manual");
							prompt("");
						} else {
							prompt("command not recognized. ? for help");

							// TO TEST: sending user input to arduino
							hcm.getSerial().message(user_input);
						}
						user_input = null;
					}
				}
			}
		});

		inputThread.start();
		prompt("Ready!");

		// TODO: Adding gamepad control
		// X axis and Y axis
		int xAxisPercentage = 0;
		int yAxisPercentage = 0;
		int xAxisMidPercentage = gamepad.getAxisValueInPercentage(gamepad
				.getXAxisValue());
		int yAxisMidPercentage = gamepad.getAxisValueInPercentage(gamepad
				.getYAxisValue());

		// Loop
		while (run == true) {
			// try {
			// Thread.sleep(0);
			// } catch (InterruptedException e) {
			// e.printStackTrace();
			// }

			// MANUAL MODE
			if (state.getMode() == State.MANUAL) {
				// System.out.println(gamepad.getYAxisValue());
				xAxisPercentage = gamepad.getAxisValueInPercentage(gamepad
						.getXAxisValue());
				yAxisPercentage = gamepad.getAxisValueInPercentage(gamepad
						.getYAxisValue());

				int drive = (yAxisMidPercentage - yAxisPercentage) * 2;
				
				if ((drive > 0) & (Math.abs(drive_prev - drive) > 10) ) {
					drive_prev = drive;
					// forward
					// Create another command object
					Command cmd = new Command(net.emo.comm.Command.MOVE);
					cmd.addParameter(net.emo.comm.Command.DIRECTION,
							net.emo.comm.Command.FORWARD);
					cmd.addParameter(net.emo.comm.Command.SPEED, drive);
					// System.out.println(cmd);

					// Convert commands to json
					try {
						// Instantiate JSON Utility class
						JsonCommands json = new JsonCommands();
						String cs = json.commandObjectToJson(cmd);
						hcm.getSerial().message(cs);
					} catch (Exception e) {
						System.out.println(e.getMessage());
					}
				} else 
				if ((drive < 5)  & (drive > -5) & (Math.abs(drive_prev - drive) > 10)) {
						drive_prev = 0;
						// forward
						// Create another command object
						Command cmd = new Command(net.emo.comm.Command.MOVE);
						cmd.addParameter(net.emo.comm.Command.DIRECTION,
								net.emo.comm.Command.STOP);
						cmd.addParameter(net.emo.comm.Command.SPEED, 0);
						// System.out.println(cmd);

						// Convert commands to json
						try {
							// Instantiate JSON Utility class
							JsonCommands json = new JsonCommands();
							String cs = json.commandObjectToJson(cmd);
							hcm.getSerial().message(cs);
						} catch (Exception e) {
							System.out.println(e.getMessage());
						}
					}
			} else {
				// backward
			}
			// System.out.println(yAxisMidPercentage-yAxisPercentage);
			gamepad.update();
		}

		hcm.getSerial().getSerialPort().close();
		prompt("Exiting. Good bye!");
	}

	public static void prompt(String text) {
		System.out.print("[emo] ");
		System.out.println(text);
	}

}
