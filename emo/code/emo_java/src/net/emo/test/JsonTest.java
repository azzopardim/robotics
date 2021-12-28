package net.emo.test;

import com.fasterxml.jackson.core.JsonProcessingException;

import net.emo.comm.Command;
import net.emo.comm.JsonCommands;
import net.emo.comm.SerialComm;
import net.emo.comm.JsonCommands.*;

public class JsonTest {

	static SerialComm arduinoComm;
	static JsonCommands json;
	
	public static void main(String[] args) {
		// Instantial serial communication to arduino
		arduinoComm = new SerialComm();
		arduinoComm.init();
		
		// TODO : Check status of serial port
		
		// Instantiate JSON Utility class
		json = new JsonCommands();
		//System.out.println(json.jsonPanCommand(net.emo.JsonCommands.LEFT));
		
		if (arduinoComm.getPortId() != null) {
		// Create a command object
		Command c = new Command(net.emo.comm.Command.PAN);
		c.addParameter(net.emo.comm.Command.DIRECTION, net.emo.comm.Command.LEFT);
		System.out.println(c);
		
		// Create another command object
		Command c2 = new Command(net.emo.comm.Command.MOVE);
		c2.addParameter(net.emo.comm.Command.DIRECTION, net.emo.comm.Command.FORWARD);
		c2.addParameter("SPEED", 100);
		System.out.println(c2);
		
		// Convert commands to json
		try {
			String cs = json.commandObjectToJson(c);
			System.out.println(cs);
			
			String cs2 = json.commandObjectToJson(c2);
			System.out.println(cs2);
			
			arduinoComm.message(cs);
			arduinoComm.message(cs2);
			
		} catch (Exception e) {
			System.out.println(e.getMessage());
		}
		} else {
			System.out.println("No serial communication available");
		}
		//TODO : Parse JSON and Update state on Arduin
		//TODO : Read jinput and translate to commands
		//TODO : Use value in Gamepad to define speed
		//TODO : Adjust speed of motor based on value
	}

}
