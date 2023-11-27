#include <iostream>
#include <vector>

std::string lcsstr(const std::string& s1, const std::string& s2) {
    int l1 = s1.length();
    int l2 = s2.length();

    std::vector<std::vector<int>> dyn_prgm(l1 + 1, std::vector<int>(l2 + 1, 0));
    int ml = 0; // maxLen
    int ei = 0; // endIndex

    for (int i = 1; i <= l1; ++i) {
        for (int j = 1; j <= l2; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dyn_prgm[i][j] = dyn_prgm[i - 1][j - 1] + 1;
                if (dyn_prgm[i][j] > ml) {
                    ml = dyn_prgm[i][j];
                    ei = i - 1;
                }
            } else {
                dyn_prgm[i][j] = 0;
            }
        }
    }

    std::string lstr = s1.substr(ei - ml + 1, ml);
    return lstr;
}

int main() {
    std::string s1 = "ABAB";
    std::string s2 = "BABA";

    std::string lcs = lcsstr(s1, s2);
    std::cout << "Longest Common Substring: " << lcs << std::endl;

    return 0;
}