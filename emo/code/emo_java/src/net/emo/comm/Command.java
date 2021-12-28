package net.emo.comm;

import java.util.HashMap;
import java.util.Map;
import java.util.ArrayList;

import com.fasterxml.jackson.annotation.JsonProperty;

public class Command {
	
	// Pan commaonds
	public static final String  PAN = "PAN";
	public static final String  LEFT = "LEFT";
	public static final String  RIGHT = "RIGHT";
	
	// Tilt commaonds
	public static final String  TILT = "TILT";
	public static final String  UP = "LEFT";
	public static final String  DOWN = "DOWN";
 
	// Move commaonds
	public static final String  MOVE = "MOVE";
	public static final String  DIRECTION = "Direction";
	public static final String  FORWARD = "FORWARD";
	public static final String  BACKWARD = "BACKWARD";
	public static final String  STOP = "STOP";
	public static final String  FORWARD_LEFT = "FORWARD_LEFT";
	public static final String  FORWARD_RIGHT = "FORWARD_RIGHT";
	public static final String  BACKWARD_LEFT = "BACKWARD_LEFT";
	public static final String  BACKWARD_RIGHT = "BACKWARD_RIGHT";
	public static final String  SPEED = "Speed";
	
	@JsonProperty("Command")  
	private String command;
	
	@JsonProperty("Parameters")  
	private ArrayList<HashMap<String, String>> parameters;
	
	public Command(String cmd) {
		command = cmd;
		parameters = new ArrayList<HashMap<String, String>>();
	}
	
	public void addParameter(String param, String value) {
		HashMap<String, String> parameter = new HashMap<String, String>();
		parameter.put(param, value);
		parameters.add(parameter);
	}
	
	public void addParameter(String param, int value) {
		Integer intValue = new Integer(value);
		HashMap<String, String> parameter = new HashMap<String, String>();
		parameter.put(param, intValue.toString());
		parameters.add(parameter);
	}
	
	public String toString() {
		String str = "COMMAND="+command;
		for (int i = 0; i < parameters.size(); i++) {
			str += ",";
			str += parameters.get(i).toString();
		}
		return str;		
	}

	public String getCommand() {
		return command;
	}

	public void setCommand(String command) {
		this.command = command;
	}
}
