// Given an n x n array, return the array elements arranged from 
// outermost elements to the middle element, traveling clockwise.

// array = [[1,2,3],
//          [4,5,6],
//          [7,8,9]]
// snail(array) #=> [1,2,3,6,9,8,7,4,5]


snail = function (a) {
	if (a.length === 1) {
		return a[0];
	}

	var finI, finT;
	var len = a.length;
	if (len % 2 !== 0) {
		finI = parseInt(len / 2);
		finT = parseInt(len / 2);
	} else {
		finI = len / 2;
		finT = len / 2 - 1;
	}

	var r = [];

	var i = 0,
		t = 0;

	var vector = {
		isLeft: false,
		isBottom: false,
		isTop: false,
		isRight: true
	};

	while (i !== finI || t !== finT) {
		if (vector.isRight)
			t = moveRight(i, t, a, r, vector);
		else if (vector.isBottom)
			i = moveBottom(i, t, a, r, vector);
		else if (vector.isLeft)
			t = moveLeft(i, t, a, r, vector);
		else if (vector.isTop)
			i = moveTop(i, t, a, r, vector);
	}
	r.push(a[finI][finT])
	return r;
}

const moveBottom = (i, t, a, r, v) => {
	while (i < a.length - 1) {
		if (a[i + 1][t] === '*') {
			v.isLeft = true;
			v.isBottom = false;
			return i;
		}
		r.push(a[i][t]);
		a[i][t] = '*';
		i++;
	}
	v.isLeft = true;
	v.isBottom = false;
	return i;
}

const moveLeft = (i, t, a, r, v) => {
	while (t > 0) {
		if (a[i][t - 1] === '*') {
			v.isTop = true;
			v.isLeft = false;
			return t;
		}
		r.push(a[i][t]);
		a[i][t] = '*';
		t--;
	}
	v.isTop = true;
	v.isLeft = false;
	return t;
}

const moveTop = (i, t, a, r, v) => {
	while (a[i - 1][t] != '*') {
		r.push(a[i][t]);
		a[i][t] = '*';
		i--;
	}
	v.isTop = false;
	v.isRight = true;
	return i;
}

const moveRight = (i, t, a, r, v) => {
	while (t < a.length - 1) {
		if (a[i][t + 1] === '*') {
			v.isRight = false;
			v.isBottom = true;
			return t;
		}
		r.push(a[i][t]);
		a[i][t] = '*';
		t++;
	}
	v.isRight = false;
	v.isBottom = true;
	return t;
}