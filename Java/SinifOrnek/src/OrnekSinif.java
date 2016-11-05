/**
 * @author      130201108 Ata Niyazov 4. Sinif I. Ogretim <130201108@kocaeli.edu.tr>
 * @version     1.0
 * @since       1.0
 */

public class OrnekSinif {
	public OrnekSinif(String x){
		mesajGenel = x + mesajGenel;
	}
	private String mesajGenel = "Varsayilan";

	public void setCourseName(String name){
		mesajGenel = name;
	}

	public String getCourseName(){
		return mesajGenel;
	}

	public void displayMessage(String courseName){
		System.out.print("girilen mesaj " + getCourseName());
	}
}
