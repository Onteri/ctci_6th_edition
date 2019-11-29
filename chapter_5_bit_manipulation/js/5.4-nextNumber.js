/* Gets next biggest integer with same amount of 1s in
 * binary representation */
const getNext = n => {
  let c = n
  let c0, c1
  c0 = c1 = 0
  while ((c & 1) == 0 && c != 0) {
    c0++
    c >>= 1
  }
  while (c & 1) {
    c1++
    c >>= 1
  }
  // position of rightmost non-trailing zero
  const p = c0 + c1
  n |= 1 << p // Flip rightmost non-trailing zero
  n &= ~((1 << p) - 1) // Clear all bits to the right of p
  n |= (1 << (c1 - 1)) - 1 // Insert (c1 - 1) ones on the right
  return n
}

console.log(getNext(0b11011001111100))
/* 11011010001111 */
