/**
 * firstNotRepeatingCharacter - Finds first non-repeating character in array
 * @s: Array of characters
 *
 * Return: First non-repeating character or '_' if none found
 */
function firstNotRepeatingCharacter(s) {
    let obj = {};
    let c;
    
    c = '_';
    for (i of s) {
        if (!obj[i]) obj[i] = 1;
        else obj[i]++;
    }
    for (let [k, v] of Object.entries(obj)) {
        if (v == 1) {
            c = k;
            break;
        }
    }
    return (c);
}
