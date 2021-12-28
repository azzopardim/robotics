package net.emo.control;

import gnu.io.SerialPortEvent;
import gnu.io.SerialPortEventListener;

import java.util.ArrayList;

import net.java.games.input.Component;
import net.java.games.input.Component.Identifier;
import net.java.games.input.Controller;
import net.java.games.input.ControllerEnvironment;




public class Gamepad {
	ArrayList<Controller> foundControllers;
	
	Controller controller;
	Component[] components;
	
	Component xAxis;
	Component yAxis;

	int controllerId = 0;
    int xAxisComponentId = 12;
    int yAxisComponentId = 13;
	
	public void initialize() {
		System.out.println("[Gamepad] Initializing gamepad controller");
		foundControllers = new ArrayList<Controller>();
        searchForControllers();	
        
        //TODO: Selecting first device on the list for now
        controller = foundControllers.get(controllerId);
        System.out.println("[Gamepad] Selected controller: "+controller.getName());
        
        
        // Getting components
        components = controller.getComponents();
        
        for (int j=0; j < components.length; j++) {
        	System.out.println("[Gamepad] Component "+j+" :"+controller.getComponents()[j].getName()+" Analog: "+controller.getComponents()[j].isAnalog());
        }
        
        xAxis = controller.getComponents()[xAxisComponentId];
        yAxis = controller.getComponents()[yAxisComponentId];
        
        
	}
	
	 /**
     * Search (and save) for controllers of type Controller.Type.STICK,
     * Controller.Type.GAMEPAD, Controller.Type.WHEEL and Controller.Type.FINGERSTICK.
     */
    public void searchForControllers() {
    	
        Controller[] controllers = ControllerEnvironment.getDefaultEnvironment().getControllers();
        System.out.println("[Gamepad] Searching for gamepad devices");
        for(int i = 0; i < controllers.length; i++){
            Controller controller = controllers[i];
            
            if (
                    controller.getType() == Controller.Type.STICK || 
                    controller.getType() == Controller.Type.GAMEPAD || 
                    controller.getType() == Controller.Type.WHEEL ||
                    controller.getType() == Controller.Type.FINGERSTICK
               )
            {
                // Add new controller to the list of all controllers.
                foundControllers.add(controller);
                
                // Add new controller to the list on the window.
                // window.addControllerName(controller.getName() + " - " + controller.getType().toString() + " type");
                System.out.println("[Gamepad] Found device "+controller.getName() + " - " + controller.getType().toString() + " type");    
            }
        }   
    }

    /**
     * Given value of axis in percentage.
     * Percentages increases from left/top to right/bottom.
     * If idle (in center) returns 50, if joystick axis is pushed to the left/top 
     * edge returns 0 and if it's pushed to the right/bottom returns 100.
     * 
     * @return value of axis in percentage.
     */
    public int getAxisValueInPercentage(float axisValue) 
    {
        return (int)(((2 - (1 - axisValue)) * 100) / 2);
    }

    public float getXAxisValue(){
    	float f = xAxis.getPollData();
    	return f;
    }
    
    public float getYAxisValue(){
    	float f = yAxis.getPollData();
    	return f;
    }

    public void update() {
    	controller.poll();
    }

}
