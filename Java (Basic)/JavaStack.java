import java.util.*;
import java.util.regex.*;

// Write your code here. DO NOT use an access modifier in your class declaration.
class Parser {
  HashMap<Character, Character> balanceMap;
  Stack<Character> charStack;

  Parser() {
    balanceMap = new HashMap<Character, Character>();
    charStack = new Stack<Character>();

    balanceMap.put(')', '(');
    balanceMap.put('}', '{');
  }

  boolean isBalanced(String input) {
    if (input.length() % 2 != 0)
      return false;

    char[] arr = input.toCharArray();

    for (char c : arr) {
      if (c == '(' || c == '{') {
        this.charStack.push(c);
      } else {
        if (!this.charStack.isEmpty() && this.balanceMap.get(c) == this.charStack.peek()) {
          this.charStack.pop();
        } else {
          return false;
        }
      }
    }

    if (this.charStack.isEmpty()) {
      return true;
    } else {
      return false;
    }
  }
}

class Solution {
  public static void main(String[] args) {
    Parser parser = new Parser();

    Scanner in = new Scanner(System.in);

    while (in.hasNext()) {
      System.out.println(parser.isBalanced(in.next()));
    }

    in.close();
  }
}