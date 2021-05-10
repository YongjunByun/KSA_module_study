package com.example.myapplication;

import java.util.ArrayList;
import java.util.Stack;

public class Calculator {
    private ArrayList<String> postfix = new ArrayList<String>();
    private Stack<Double> stack = new Stack<>();        // Used stack because it has all functions needed for postfix
    // Push to last, pop last digit are the only required
    public Calculator(ArrayList<String> postfix) {
        this.postfix = postfix;
    }

    public double result() {
        for (int i = 0; i < postfix.size(); i++) {
            if (Character.isDigit(postfix.get(i).charAt(0)) || postfix.get(i).charAt(0) == '.') {
                stack.push(Double.parseDouble(postfix.get(i)));
            } else {
                double one;
                double two;

                switch (postfix.get(i)) {
                    case "+":
                        one = stack.pop();
                        two = stack.pop();
                        stack.push(two+one);
                        break;
                    case "-":                           // Does TWO - ONE because ONE is removed before TWO
                        one = stack.pop();              // "3 2 -" results in ONE as 2 and TWO as 3 (must do 3-2, which is TWO-ONE
                        two = stack.pop();
                        stack.push(two-one);
                        break;
                    case "*":
                        one = stack.pop();
                        two = stack.pop();
                        stack.push(two*one);
                        break;
                    case "/":
                        one = stack.pop();
                        two = stack.pop();
                        stack.push(two/one);
                        break;
                    case "^":
                        one = stack.pop();
                        two = stack.pop();
                        stack.push(Math.pow(two, one));
                        break;
                    case "c":
                        one = stack.pop();
                        stack.push(Math.cos(one));
                        break;
                    case "s":
                        one = stack.pop();
                        stack.push(Math.sin(one));
                        break;
                    case "t":
                        one = stack.pop();
                        stack.push(Math.tan(one));
                        break;
                    case "l":
                        one = stack.pop();
                        stack.push(Math.log10(one));
                        break;

                }
            }
        }
        return stack.pop();
    }
}