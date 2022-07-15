import java.util.Scanner;

class Box{
	int height=1, width=1, depth=1;
	Box(){
		height=3;
		width=4;
		depth=5;
	}
	Box(int dim){
		// System.out.println("Cube Generated")
		height=dim;
		width=dim;
		depth=dim;
	}
	Box(int height, int width, int depth){
		this.height = height;
		this.width = width;
		this.depth = depth;
	} 

	void setData(int height, int width, int depth){
		this.height = height;
		this.width = width;
		this.depth = depth;	
	}

	int getVolume(){
		return (this.height*this.width*this.depth);
	}
}

public class BoxTest{
	public static void main(String[] args) {
		System.out.println("\n\nAssignment 1 - Part A");
		Box boxObj = new Box();
		int h = Integer.parseInt(args[0]);
		int w = Integer.parseInt(args[1]);
		int d = Integer.parseInt(args[2]);
		boxObj.setData(h, w, d);
		System.out.println("Volume is "+boxObj.getVolume());

		System.out.println("\n\nAssignment 1 - Part B");
		Scanner in = new Scanner(System.in);
		System.out.print("Enter height, width, depth of Rectangular Box : ");
		h = in.nextInt();
		w = in.nextInt();
		d = in.nextInt();
		Box rectBox = new Box(h,w,d);
		int rectVol = rectBox.getVolume();
		System.out.println("Volume of Rectangular Box : "+rectVol);

		System.out.print("\nEnter dimension of cube : ");
		d = in.nextInt();
		Box cubeBox = new Box(d);
		int cubeVol = cubeBox.getVolume();
		System.out.println("Volume of Cube : "+cubeVol);

		if(cubeVol>rectVol) System.out.println("\n Cuboid volume is greater than Rectangular Box.");
		else System.out.println("\n Rectangular Box volume is greater than Cuboid.");

	}
}