
public class HashTable {
	
	public static int hash(String word, int tablesize) {
		// hash function for hashing strings
		return Math.abs(word.hashCode()) % tablesize;
	}
	
	public static int makeTable(String[] words) {
		// count number of collisions and words hashed
		int coll = 0;
		int hashCount = 0;
		// starting hashtable
		String[] table = new String[31];
		// loop through hashing each word
		for(int i = 0; i < words.length; i++) {
			// determine hash value of word
			int hashvalue = hash(words[i], table.length);
			// if space available then place at hash value
			if(table[hashvalue] == null) {
				table[hashvalue] = words[i];
				hashCount++;
			}
			//else use quadratic probe to find next open space
			else {
				coll++;
				int quad = 1;
				while(table[(hashvalue + quad*quad)%table.length] != null) {
					coll++;
					quad += 1;
				}
				table[(hashvalue+quad*quad)%table.length] = words[i];
				hashCount++;
			}
			// if the load factor > .5 make new table and rehash
			if(hashCount*2 > table.length) {
				// reset collisions
				coll = 0;
				// make new table
				String[] newTable = new String[table.length * 2];
				int newCount = 0;
				// rehash words that have already been hashed
				for(int j = 0; j < hashCount; j++) {
					hashvalue = hash(words[j], newTable.length);
					if(newTable[hashvalue] == null) {
						newTable[hashvalue] = words[j];
						newCount++;
					}
					else {
						coll++;
						int quad = 1;
						while(newTable[(hashvalue + quad*quad)%newTable.length] != null) {
							coll++;
							quad += 1;
						}
						newTable[(hashvalue+quad*quad)%newTable.length] = words[j];
						newCount++;
					}
				}
				// reset hashCount and set table to new table
				hashCount = newCount;
				table = newTable;
			}
		}
		System.out.println("Printing Hashtable: ");
		for(int k = 0; k < table.length; k++) {
			if(table[k] != null) {
				System.out.print("Position: " + k);
				System.out.println(" Word: " + table[k]);
			}
		}
		return coll;
	}

	public static void main(String[] args) {
		String[] words = {"art", "cat", "MAN", "Door", "Boat", "ZOOS", "Doors", "BOATS", "ZEBRA", "fuzzy", "absorb", "Zygote", "muting", "Jazzing", "puzzles", "Quantum", "oxidized", "PLAYBACK", "Adjuncts", "jeopardy"};
		System.out.println("Number of collisions: " + makeTable(words));
	}
}
