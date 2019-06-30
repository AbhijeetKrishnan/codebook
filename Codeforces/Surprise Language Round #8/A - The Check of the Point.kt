fun main(args: Array<String>) {
    val (a, x, y) = readLine()!!.split(' ').map(String::toInt)
    var ans = 2
	if (x > 0 && x < a && y > 0 && y < a)
		ans = 0
	else if (x >= 0 && x <= a && y >= 0 && y <= a)
		ans = 1
	println(ans)
}