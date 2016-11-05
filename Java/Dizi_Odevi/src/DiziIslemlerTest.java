/**
 * @author      130201108 Ata Niyazov 4. Sinif I. Ogretim <130201108@kocaeli.edu.tr>
 * @version     1.0
 * @since       1.0
 */

public class DiziIslemlerTest {

	public static class DiziIslemler {
		int[] diziOlustur(int length, int start, int end) {

			if (start > end) {
				int temp = start;
				start = end;
				end = temp;
			}

			int[] array = new int[length];

			for (int i = 0; i < length; i++) {
				array[i] = start + ((int) (Math.random() * (end - start))) + 1;
			}

			return array;
		}

		void diziGoster(int[] array) {
			for (int index : array) {
				System.out.print(index + " ");
			}
			System.out.println();
		}

		int[] matrisAktar(int[][] matrix) {
			int[] array = new int[(matrix[0].length + matrix[1].length)];

			int i0 = 0;
			int i1 = 0;

			int i = 0;
			while (i0 < matrix[0].length && i1 < matrix[1].length) {
				if (matrix[0][i0] < matrix[1][i1]) {
					array[i++] = matrix[0][i0++];
				} else {
					array[i++] = matrix[1][i1++];
				}
			}

			if (i0 < matrix[0].length) {
				while (i0 < matrix[0].length) {
					array[i++] = matrix[0][i0++];
				}
			}

			if (i1 < matrix[1].length) {
				while (i1 < matrix[1].length) {
					array[i++] = matrix[1][i1++];
				}
			}

			return array;
		}

		int buyukElemanBul(int[] array) {

			int mostValue = 0;

			for (int index : array) {
				if (mostValue < index) {
					mostValue = index;
				}
			}
			return mostValue;
		}
	}

	public static void main(String[] args) {

		DiziIslemler islem = new DiziIslemler();

		int[] array = islem.diziOlustur(10, 1, 100);
		islem.diziGoster(array);
		System.out.println(islem.buyukElemanBul(array));

		System.out.println();

		int[][] matrix = { { 1, 3, 5, 7, 9 }, { 2, 4, 6, 8, 10 } };
		// System.out.println("0: " + matrix.length + "\n1: " + matrix[0].length + "\n1: " + matrix[1].length);

		int[] arrayFromMatrix = islem.matrisAktar(matrix);
		islem.diziGoster(arrayFromMatrix);
		System.out.println(islem.buyukElemanBul(arrayFromMatrix));

	}
}
