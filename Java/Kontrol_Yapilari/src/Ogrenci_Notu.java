/**
 * @author      130201108 Ata Niyazov 4. Sinif I. Ogretim <130201108@kocaeli.edu.tr>
 * @version     1.0
 * @since       1.0
 */

import javax.swing.JOptionPane;

public class Ogrenci_Notu {

	public static void main(String[] args) {

		double vizeNotu = Integer.parseInt(JOptionPane.showInputDialog("Vize notunuzu giriniz:"));
		double labNotu = Integer.parseInt(JOptionPane.showInputDialog("Lab notunuzu giriniz:"));
		double finalNotu = Integer.parseInt(JOptionPane.showInputDialog("Final notunuzu giriniz:"));

		int notOrtalama = (int) ((vizeNotu * 0.3) + (labNotu * 0.25) + (finalNotu * 0.45));

		String basariNotu = null;

		if (notOrtalama >= 65 && notOrtalama <= 100) {
			if (notOrtalama >= 90 && notOrtalama <= 100) {
				basariNotu = "AA";
			} else if (notOrtalama >= 85 && notOrtalama <= 89) {
				basariNotu = "BA";
			} else if (notOrtalama >= 80 && notOrtalama <= 84) {
				basariNotu = "BB";
			} else if (notOrtalama >= 75 && notOrtalama <= 79) {
				basariNotu = "CB";
			} else if (notOrtalama >= 65 && notOrtalama <= 74) {
				basariNotu = "CC";
			}
			JOptionPane.showMessageDialog(null, "Basari Notunuz: " + basariNotu, "Basari Notu",
					JOptionPane.INFORMATION_MESSAGE);
		} else if (notOrtalama >= 0 && notOrtalama <= 64) {
			if (notOrtalama >= 58 && notOrtalama <= 64) {
				basariNotu = "DC";
			} else if (notOrtalama >= 50 && notOrtalama <= 57) {
				basariNotu = "DD";
			} else if (notOrtalama >= 40 && notOrtalama <= 49) {
				basariNotu = "FD";
			} else if (notOrtalama <= 39) {
				basariNotu = "FF";
			}
			JOptionPane.showMessageDialog(null, "Basari Notunuz: " + basariNotu, "Basari Notu",
					JOptionPane.INFORMATION_MESSAGE);
			if (JOptionPane.showConfirmDialog(null, "But Sinavina girmek isteyor musunuz?", "But Sinavi",
					JOptionPane.YES_NO_OPTION) == 0) {
				double butNotu = Integer.parseInt(JOptionPane.showInputDialog("But notunuzu giriniz:"));
				notOrtalama = (int) ((vizeNotu * 0.3) + (labNotu * 0.25) + (butNotu * 0.45));

				if (notOrtalama >= 65 && notOrtalama <= 100) {
					if (notOrtalama >= 90 && notOrtalama <= 100) {
						basariNotu = "AA";
					} else if (notOrtalama >= 85 && notOrtalama <= 89) {
						basariNotu = "BA";
					} else if (notOrtalama >= 80 && notOrtalama <= 84) {
						basariNotu = "BB";
					} else if (notOrtalama >= 75 && notOrtalama <= 79) {
						basariNotu = "CB";
					} else if (notOrtalama >= 65 && notOrtalama <= 74) {
						basariNotu = "CC";
					}
					JOptionPane.showMessageDialog(null, "Basari Notunuz: " + basariNotu, "Basari Notu",
							JOptionPane.INFORMATION_MESSAGE);
				} else if (notOrtalama >= 0 && notOrtalama <= 64) {
					if (notOrtalama >= 58 && notOrtalama <= 64) {
						basariNotu = "DC";
					} else if (notOrtalama >= 50 && notOrtalama <= 57) {
						basariNotu = "DD";
					} else if (notOrtalama >= 40 && notOrtalama <= 49) {
						basariNotu = "FD";
					} else if (notOrtalama <= 39) {
						basariNotu = "FF";
					}
					JOptionPane.showMessageDialog(null, "Basari Notunuz: " + basariNotu, "Basari Notu",
							JOptionPane.INFORMATION_MESSAGE);
				} else {
					JOptionPane.showMessageDialog(null, "Hatali Giris" + basariNotu, "Hatali Giris",
							JOptionPane.ERROR_MESSAGE);
				}
			}
			;
		} else {
			JOptionPane.showMessageDialog(null, "Hatali Giris" + basariNotu, "Hatali Giris", JOptionPane.ERROR_MESSAGE);
		}
	}
}
