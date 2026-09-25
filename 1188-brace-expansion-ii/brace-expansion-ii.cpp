#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cctype>

class Solution {
public:
    std::vector<std::string> braceExpansionII(std::string expression) {
        int i = 0;
        std::set<std::string> resultSet = parseUnion(expression, i);
        return std::vector<std::string>(resultSet.begin(), resultSet.end());
    }

private:
    // Cartesian product of two sets
    std::set<std::string> product(const std::set<std::string>& A, const std::set<std::string>& B) {
        if (A.empty()) return B;
        if (B.empty()) return A;
        std::set<std::string> res;
        for (const std::string& a : A) {
            for (const std::string& b : B) {
                res.insert(a + b);
            }
        }
        return res;
    }

    // Union of two sets
    void unionSets(std::set<std::string>& dest, const std::set<std::string>& src) {
        dest.insert(src.begin(), src.end());
    }

    // Handles comma-separated terms (Union / Addition)
    std::set<std::string> parseUnion(const std::string& s, int& i) {
        std::set<std::string> result;
        while (i < s.size() && s[i] != '}') {
            std::set<std::string> term = parseConcat(s, i);
            unionSets(result, term);
            if (i < s.size() && s[i] == ',') {
                i++; // Skip ','
            }
        }
        return result;
    }

    // Handles adjacent concatenated terms (Cartesian Product / Multiplication)
    std::set<std::string> parseConcat(const std::string& s, int& i) {
        std::set<std::string> result = {""}; // Identity for concatenation

        while (i < s.size() && s[i] != '}' && s[i] != ',') {
            std::set<std::string> factor;
            if (s[i] == '{') {
                i++; // Skip '{'
                factor = parseUnion(s, i);
                i++; // Skip '}'
            } else if (std::isalpha(s[i])) {
                std::string word = "";
                while (i < s.size() && std::isalpha(s[i])) {
                    word += s[i++];
                }
                factor = {word};
            }
            result = product(result, factor);
        }
        return result;
    }
};