public class Circle extends PrintableObject implements Shape{
	double radius;

	public double getRadius() {
		return radius;
	}

	public void setRadius(double radius) {
		this.radius = radius;
	}
	
	//No-args constructor
	public Circle() {
		System.out.println("Circle is created");
	}
	
	//Constructor to get value from the user
	public Circle(double radius) {
		this.radius=radius;
	}
	
	@Override
	public String toString() {
		return (super.toString()+","+radius);
	}
		
	public static Circle parse(String input) {
		
		/*As the input is in given by the format as Circle,radius
		 * so split the string by ,(comma) and we store it in the string array.*/
		String[] givenInput=input.split(",");
		//Parsing the value in double
		double radius=Double.parseDouble(givenInput[1]);
		return new Circle(radius);
	}
	@Override
	public double getPerimeter() {
		return 2*Math.PI*this.radius;
	}
	
	@Override
	public double getArea(){
		return Math.PI*this.radius*this.radius;
	}
	
	@Override
	public String getName() {
		return "CIRCLE";
	}
}
