
public class Rectangle extends PrintableObject implements Shape {
	double length,breath;
	
	//Accessors and mutators
	public double getLength() {
		return length;
	}
	public void setLength(double length) {
		this.length = length;
	}
	public double getBreath() {
		return breath;
	}
	public void setBreath(double breath) {
		this.breath = breath;
	}
	
	//No-args constructor
	public Rectangle() {
		System.out.println("Rectangle is created");
	}
	
	//Constructor to get value from the user
	public Rectangle(double length,double breath) {
		this.length=length;
		this.breath=breath;
	}
	
	@Override
	public String toString() {
		return (super.toString()+","+length+","+breath);
	}
	
	/*@Override
	public String getName() {
		return ("ClassName Rectangle");
	}*/
	
	public static Rectangle parse(String input) {
		
		/*As the input is in given by the format as Rectangle,length,breath
		 * so split the string by ,(comma) and we store it in the string array.*/
		String[] givenInput=input.split(",");
		//Parsing the value in double
		double length=Double.parseDouble(givenInput[1]);
		double breath=Double.parseDouble(givenInput[2]);
		return new Rectangle(length,breath);
	}
	
	@Override
	public double getPerimeter() {
		return (2*(this.length+this.breath));
	}
	
	@Override
	public double getArea() {
		return (this.length*this.breath);
	}
}
