/**
 * @param {string} s
 * @return {boolean}
 */
var checkValidString = function (s) {
    let m = {};
    return checkValidStringHelper(s, 0, 0, m);
};

var checkValidStringHelper = function (s, i, k, m) {
    if (i == s.length && k == 0) {
        return true;
    } else if (k < 0 || i == s.length) {
        return false;
    }

    if (m.hasOwnProperty(i + "-" + k)) {
        return m[i + "-" + k];
    }
    let isValid = false;
    if (s[i] == '(') {
        isValid = checkValidStringHelper(s, i + 1, k + 1, m);
    } else if (s[i] == ')') {
        isValid = checkValidStringHelper(s, i + 1, k - 1, m);
    } else {
        let l1 = checkValidStringHelper(s, i + 1, k, m);
        let l2 = checkValidStringHelper(s, i + 1, k + 1, m);
        let l3 = checkValidStringHelper(s, i + 1, k - 1, m);
        isValid = l1 || l2 || l3;
    }
    m[i + "-" + k] = isValid;
    return isValid;
};