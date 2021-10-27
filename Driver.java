import java.util.*;
import java.io.*;

public class Driver {

	public static void main(String[] args) throws FileNotFoundException {
		try {
			Scanner obj = new Scanner(System.in);
			System.out.println("Name of the file which consits the shapes.");
			String fileName = obj.nextLine();
			File file = new File(fileName);
			Scanner fileReader_size = new Scanner(file);
			Scanner fileReader_name = new Scanner(file);
			int count = 0;
			while (fileReader_size.hasNextLine()) {
				fileReader_size.nextLine();
				count++;
			}
			Shape[] shapeArray = new Shape[count];
			int i = 0;

			while (fileReader_name.hasNextLine()) {
				String line = fileReader_name.nextLine();
				String[] shapeName = line.split(",");
				if (shapeName[0].equalsIgnoreCase("Rectangle")) {
					System.out.println("Rectangle with sides: Length:" + shapeName[1] + "\tBreadth:" + shapeName[2]);
					Rectangle r = new Rectangle();
					r.length = Double.parseDouble(shapeName[1]);
					r.breath = Double.parseDouble(shapeName[2]);
					PrintableObject rectangle = new Rectangle(Double.parseDouble(shapeName[1]),
							Double.parseDouble(shapeName[2]));
					// Rectangle.parse(line);
					System.out.println("Area=" +rectangle.getArea());
					System.out.println("Perimeter="+rectangle.getPerimeter());
					shapeArray[i] = r;
					i++;
				} else if (shapeName[0].equalsIgnoreCase("Circle")) {
					System.out.println("Circle with radius of " + shapeName[1]);
					Circle c = new Circle();
					c.radius = Double.parseDouble(shapeName[1]);
					PrintableObject circle = new Circle(Double.parseDouble(shapeName[1]));
					System.out.println("Area="+circle.getArea());
					System.out.println("Perimeter="+circle.getPerimeter());
					shapeArray[i] = c;
					i++;
				}
			}
			obj.close();
			fileReader_size.close();
			fileReader_name.close();
			for (int j = 0; j < count; j++) {
				System.out.println(shapeArray[j]);
			}
			
			//Sort the array in ascending order
			Arrays.sort(shapeArray,new Comparator<Shape>() {
				public int compare(Shape obj1,Shape obj2) {
					if(obj1.getName().compareTo(obj2.getName())>0) {
						return 1;
					}else if(obj1.getName().compareTo(obj2.getName())<0) {
						return -1;
					}else {
						if(obj1.getArea()>obj2.getArea()) {
							return 1;
						}else if(obj1.getArea()<obj2.getArea()) {
							return -1;
						}
					}
					return 0;
				}
			});
			System.out.println("\n\nSorted array");
			//Printing Shapes by calling the print method
			for(Shape shape:shapeArray){
				Printable printable=(Printable) shape;
				printable.print();
			}
			
		} catch (IOException e) {
			e.printStackTrace();
		}
		
	}
}