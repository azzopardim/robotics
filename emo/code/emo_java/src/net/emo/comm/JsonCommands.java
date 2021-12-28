package net.emo.comm;

import java.io.IOException;

import com.fasterxml.jackson.core.JsonGenerator;
import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.JsonNode;
import com.fasterxml.jackson.databind.ObjectMapper;


public class JsonCommands {

	

	public void parseString(String str) throws JsonProcessingException, IOException {
		String jsonString = "{\"k1\":\"v1\",\"k2\":\"v2\"}";
		 
	    ObjectMapper mapper = new ObjectMapper();
	    JsonNode actualObj = mapper.readTree(jsonString);
	}
 
	public String jsonPanCommand(String direction) {
		String msgType = "command";
		String command = "pan";
		String cmdAttr = direction;
		String jsonString = "["+"command="+msgType+","+command+"="+cmdAttr+"]";
		return jsonString;
	}
	
	public String commandObjectToJson(Command cmd) throws JsonProcessingException {
		ObjectMapper mapper = new ObjectMapper();
		String cmdString = new String();
		cmdString = mapper.writeValueAsString(cmd);
		return cmdString;
	}
}
