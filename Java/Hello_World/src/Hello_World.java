/**
 * @author      130201108 Ata Niyazov 4. Sinif I. Ogretim <130201108@kocaeli.edu.tr>
 * @version     1.0
 * @since       1.0
 */

import javax.swing.JOptionPane;

public class Hello_World {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("Hello World");
		JOptionPane.showMessageDialog(null, "Test");
		String str = JOptionPane.showInputDialog("Adini gir:");
		System.out.println("You typed " + str);

	}

}
