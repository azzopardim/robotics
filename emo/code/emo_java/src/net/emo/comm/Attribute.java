package net.emo.comm;

import java.util.AbstractMap;
import java.util.ArrayList;

import com.fasterxml.jackson.annotation.JsonProperty;

public class Attribute {
	@JsonProperty("Attribute")  
	private String attribute;
	
	@JsonProperty("Parameters")  
	private ArrayList<AbstractMap.SimpleEntry<String, String>> parameters;

	public String getAttribute() {
		return attribute;
	}

	public void setAttribute(String attribute) {
		this.attribute = attribute;
	}

	public ArrayList<AbstractMap.SimpleEntry<String, String>> getParameters() {
		return parameters;
	}

	public void setParameters(
			ArrayList<AbstractMap.SimpleEntry<String, String>> parameters) {
		this.parameters = parameters;
	}
	
	
}
