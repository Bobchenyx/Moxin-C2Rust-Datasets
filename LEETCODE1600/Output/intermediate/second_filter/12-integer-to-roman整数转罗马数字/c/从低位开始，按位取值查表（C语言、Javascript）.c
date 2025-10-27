/**
 * @param {number} num
 * @return {string}
 */
var intToRoman = function(num) {
  const romanCharFive = ['V', 'L', 'D']
  const romanCharOne = ['I', 'X', 'C', 'M']
  let pointer = 0
  let result = ''
  while (num > 0) {
    const digits = num % 10
    switch (digits) {
      case 1:
      case 2:
      case 3:
        result = `${romanCharOne[pointer].padStart(
          digits,
          romanCharOne[pointer]
        )}${result}`
        break
      case 4:
        result = `${romanCharOne[pointer]}${romanCharFive[pointer]}${result}`
        break
      case 5:
        result = `${romanCharFive[pointer]}${result}`
        break
      case 6:
      case 7:
      case 8:
        result = `${romanCharFive[pointer]}${romanCharOne[pointer].padStart(
          digits - 5,
          romanCharOne[pointer]
        )}${result}`
        break
      case 9:
        result = `${romanCharOne[pointer]}${romanCharOne[pointer + 1]}${result}`
        break
    }
    // JS 中的 number 为 64 位浮点数，此处位运算用于取整
    // parseInt(3.14,10) 和 3.14 >> 0 返回值是一致的
    num = (num / 10) >> 0
    pointer++
  }
  return result
}