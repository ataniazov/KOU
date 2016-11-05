/**
 * @author      130201108 Ata Niyazov 4. Sinif I. Ogretim <130201108@kocaeli.edu.tr>
 * @version     1.0
 * @since       1.0
 */

import javax.swing.JOptionPane;

public class Silindir {
	public static void main(String[] args) {
		boolean alive = true;
		do {
			String secim = JOptionPane.showInputDialog(null,
					"A: Silindirin Hacim Hesabı\nB: Silindirin Yüzey Alan Hesabı\nC: Çıkış", "MENU",
					JOptionPane.QUESTION_MESSAGE);
			if (secim.equals("A") || secim.equals("a")) {
				JOptionPane.showMessageDialog(null, "Seciminiz: " + secim.toUpperCase(), "Seciminiz",
						JOptionPane.INFORMATION_MESSAGE);
				int yariCap = Integer.parseInt(JOptionPane.showInputDialog(null, "Yari Cap giriniz: ",
						"Silindirin Hacim Hesabı", JOptionPane.QUESTION_MESSAGE));
				int yukseklik = Integer.parseInt(JOptionPane.showInputDialog(null, "Yuksekligi giriniz: ",
						"Silindirin Hacim Hesabı", JOptionPane.QUESTION_MESSAGE));
				float hacim = (float) (Math.PI * Math.pow(yariCap, 2) * yukseklik);
				JOptionPane.showMessageDialog(null, "Silindirin Hacimi: " + hacim, "Silindirin Hacim Hesabı",
						JOptionPane.INFORMATION_MESSAGE);
			} else if (secim.equals("B") || secim.equals("b")) {
				JOptionPane.showMessageDialog(null, "Seciminiz: " + secim.toUpperCase(), "Seciminiz",
						JOptionPane.INFORMATION_MESSAGE);
				int yariCap = Integer.parseInt(JOptionPane.showInputDialog(null, "Yari Cap giriniz: ",
						"Silindirin Yuzey Alan Hesabı", JOptionPane.QUESTION_MESSAGE));
				int yukseklik = Integer.parseInt(JOptionPane.showInputDialog(null, "Yuksekligi giriniz: ",
						"Silindirin Yuzey Alan Hesabı", JOptionPane.QUESTION_MESSAGE));
				float yuzeyAlan = (float) (2 * Math.PI * yariCap * (yariCap + yukseklik));
				JOptionPane.showMessageDialog(null, "Silindirin Yuzey Alani: " + yuzeyAlan,
						"Silindirin Yuzey Alan Hesabı", JOptionPane.INFORMATION_MESSAGE);
			} else if (secim.equals("C") || secim.equals("c")) {
				alive = false;
			} else {
				JOptionPane.showMessageDialog(null, "Hatali Giris: " + secim, "Hatali Giris",
						JOptionPane.ERROR_MESSAGE);
			}
		} while(alive);
	}
}
