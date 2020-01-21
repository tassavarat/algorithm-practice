/**
 * rotateImage - Rotates 2D array 90 degrees clockwise
 * @a: 2D array to rotate
 *
 * Return: Rotated 2D array
 */
function rotateImage (a) {
  let i, j;
  const tmp = [];

  for (i = 0; i < a.length; ++i) {
    tmp.push([]);
    for (j = a.length - 1; j > -1; --j) {
      tmp[i].push(a[j][i]);
    }
  }
  return (tmp);
}
