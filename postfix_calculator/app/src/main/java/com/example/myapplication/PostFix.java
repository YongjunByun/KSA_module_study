package com.example.myapplication;

import java.util.ArrayList;
import java.util.Stack;
import java.util.StringTokenizer;

public class PostFix {
    private String original;
    private ArrayList<String> postfix = new ArrayList<String>();
    private Stack<Character> stack = new Stack<>();

    public PostFix(String expression)
    {
        original = expression;
        convertExpression();
    }

    public void convertExpression() {
        StringTokenizer tokenizer = new StringTokenizer(original, "+-*/^()", true);


        while (tokenizer.hasMoreTokens()) {
            String token = tokenizer.nextToken();
            if (Character.isDigit(token.charAt(0))) {
                postfix.add(token);
            } else {
                addToStack(token.charAt(0));
            }
        }
        addStackToPostFix();
    }


    public void addToStack(char input) {
        if(stack.isEmpty() || input == '(')
            stack.push(input);
        else {
            if(input == ')') {
                while(!stack.peek().equals('(')) {
                    postfix.add(stack.pop().toString());
                }
                stack.pop();
            }
            else {
                if(stack.peek().equals('('))
                    stack.push(input);
                else {
                    if (getPrecedence(input) <= getPrecedence(stack.peek())) {
                        while(!stack.isEmpty() && !(stack.peek() == '('))  {
                            postfix.add(stack.pop().toString());
                        }
                    }
                    stack.push(input);
                }
            }
        }
    }

    public int getPrecedence(char op)
    {
        switch (op) {
            case '+':
                return 1;
            case '-':
                return 1;
            case '*':
                return 2;
            case '/':
                return 2;
            case '^':
                return 3;
            case 'c':
                return 3;
            case 's':
                return 3;
            case 't':
                return 3;
            case 'l':
                return 3;
            default:
                return 0;
        }
    }

    public void addStackToPostFix()
    {
        while(!stack.isEmpty())
        {
            postfix.add(stack.pop().toString());
        }
    }

    public ArrayList<String> getPostfixAsList()
    {
        return postfix;
    }
}