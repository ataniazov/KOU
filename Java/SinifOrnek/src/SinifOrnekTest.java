/**
 * @author      130201108 Ata Niyazov 4. Sinif I. Ogretim <130201108@kocaeli.edu.tr>
 * @version     1.0
 * @since       1.0
 */

import java.util.Scanner;

public class SinifOrnekTest {
	public static void main(String[] args){
		Scanner input = new Scanner(System.in);
		OrnekSinif myGradeBook = new OrnekSinif("Baslama");
		// myGradeBook.displayMessage(input.next());
		System.out.println("Baslangic " + myGradeBook.getCourseName());
		
		System.out.println("Bir mesaj giriniz : ");
		String m = input.nextLine();
		
		myGradeBook.setCourseName(m);
		System.out.println("Yeni Mesaj = " + myGradeBook.getCourseName());

		/*
		int a = input.nextInt();
		double d = input.nextDouble();
		byte b = input.nextByte();
		*/
	}
}
