package com.example.myapplication;

import androidx.annotation.RequiresApi;
import androidx.appcompat.app.AppCompatActivity;

import android.os.Build;
import android.os.Bundle;
import android.text.SpannableStringBuilder;
import android.view.View;
import android.widget.TextView;
import android.widget.EditText;
//import android.widget.Button;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.Stack;
public class MainActivity extends AppCompatActivity {

//    static String StrToAdd;
    private TextView TextOutput;
    private EditText TextInput;

    String expression = "";
    String answer = "";
    PostFix pc;
    Calculator calc;
    ArrayList<String> list = new ArrayList<>();
    boolean pause = false;

    @RequiresApi(Build.VERSION_CODES.LOLLIPOP)
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
//        tvexpression = findViewById(R.id.tvexpression);
//        tvanswer = findViewById(R.id.tvanswer);
        TextOutput = findViewById(R.id.TextOutput);
        TextInput = findViewById(R.id.TextInput);
        TextInput.setShowSoftInputOnFocus(false);
    }

    


    private void updateText (String StrToAdd) {
        String oldStr = TextInput.getText().toString();

        int cursorPos = TextInput.getSelectionStart();
        String LeftStr = oldStr.substring(0, cursorPos);
        String RightStr = oldStr.substring(cursorPos);

        TextInput.setText(String.format("%s%s%s", LeftStr, StrToAdd, RightStr));
        TextInput.setSelection(cursorPos + StrToAdd.length());


    }


    public void BtnLeftPar(View view) {
        updateText(getResources().getString(R.string.TextLeftPar));
        expression += "(";                      // it will compute whatever is after the open parenthesis --> if this happens,
        pause = true;                           // an error will occur because the postfix converter can not detect the proper order
    }

    public void BtnRightPar(View view) {
        updateText(getResources().getString(R.string.TextRightPar));
        expression += ")";                      // Close parenthesis sets PAUSE to false to let the postfix converter continue setting
        pause = false;
    }

    public void BtnLog(View view) {
        updateText(getResources().getString(R.string.TextLog)); //로그 함수 ======================     log(
        expression += "l";
        expression += "(";
    }

    public void BtnFactorial(View view) {
        updateText(getResources().getString(R.string.TextFactorial));
<<<<<<< HEAD
        expression += "(";
        expression += "f";
        expression += ")";
=======
>>>>>>> 077949ecaa7b54625af5a06424f35acf17c622c2
    } //팩토리얼 =========================================

    public void BtnSquare(View view) {
        updateText(getResources().getString(R.string.TextSquare));
        expression += "^";
    }

    //================================================================

    public void BtnSin(View view) {
        updateText(getResources().getString(R.string.TextSin)); //Sin ===========================
        expression += "s";
        expression += "(";
    }

    public void BtnCos(View view) {
        updateText(getResources().getString(R.string.TextCos)); //Cos ===========================
        expression += "c";
        expression += "(";
    }

    public void BtnTan(View view) {
        updateText(getResources().getString(R.string.TextTan)); //tan ===========================
        expression += "t";
        expression += "(";
    }

    public void BtnClear(View view) {
        TextInput.setText(""); //Clear =========================
        clear();
    }

    public void BtnDelete(View view) {
        int CursorPos = TextInput.getSelectionStart(); //Delete ======================
        int textLen = TextInput.getText().length();
        expression=expression.substring(0, expression.length()-1); //

        if (CursorPos != 0 && textLen != 0) {
            SpannableStringBuilder selection = (SpannableStringBuilder) TextInput.getText();
            selection.replace (CursorPos-1, CursorPos, "");
            TextInput.setText(selection);
            TextInput.setSelection(CursorPos-1);
        }
    }

    //================================================================

    public void BtnSeven(View view) {
        updateText(getResources().getString(R.string.TextSeven));
        expression += "7";
    }

    public void BtnEight(View view) {
        updateText(getResources().getString(R.string.TextEight));
        expression += "8";
    }

    public void BtnNine(View view) {
        updateText(getResources().getString(R.string.TextNine));
        expression += "9";
    }

    public void BtnSum(View view) {
        updateText(getResources().getString(R.string.TextSum));
        expression += "+";
    }

    //================================================================

    public void BtnFour(View view) {
        updateText(getResources().getString(R.string.TextFour));
        expression += "4";
    }

    public void BtnFive(View view) {
        updateText(getResources().getString(R.string.TextFive));
        expression += "5";
    }

    public void BtnSix(View view) {
        updateText(getResources().getString(R.string.TextSix));
        expression += "6";
    }

    public void BtnMinus(View view) {
        updateText(getResources().getString(R.string.TextMinus));
        expression += "-";
    }

    public void BtnOne(View view) {
        updateText(getResources().getString(R.string.TextOne));
        expression += "1";
    }

    public void BtnTwo(View view) {
        updateText(getResources().getString(R.string.TextTwo));
        expression += "2";
    }

    public void BtnThree(View view) {
        updateText(getResources().getString(R.string.TextThree));
        expression += "3";
    }

    public void BtnMul(View view) {
        updateText(getResources().getString(R.string.TextMul));
        expression += "*";
    }

    public void BtnDot(View view) {
        updateText(getResources().getString(R.string.TextDot));
        expression += ".";
    }

    public void BtnZero(View view) {
        updateText(getResources().getString(R.string.TextZero));
        expression += "0";
    }

    public void BtnEqual(View view) {

        if (checkValid(toCalculate(expression)) && expression.length() > 0) {
            expression = toCalculate(expression);
            calculate();
            TextOutput.setText(toExpression(expression));
            TextOutput.setText(answer);
        }

        if (TextOutput.length() > 0 && TextOutput.getText().equals("Infinity") || TextOutput.getText().equals("NaN") || TextOutput.getText().equals("-Infinity")) {
            clear();
            TextOutput.setText("Error");                                    // These answers cause errors if they are set to expression (calculator cannot do postfix of strings)
            TextOutput.setText("");
        }
        expression = answer;                    // Sets expression to answer (to use answer in the next calculation)
    }

    public void BtnDiv(View view) {
        updateText(getResources().getString(R.string.TextDiv));
        expression += "/";
    }



    public void calculate() {
<<<<<<< HEAD
        if (expression.length() > 0 && (Character.isDigit(expression.charAt(expression.length() - 1))
                || expression.charAt(expression.length() - 1) == ')') && !pause|| expression.charAt(expression.length() - 1) == 'f') {
=======
        if (expression.length() > 0 && (Character.isDigit(expression.charAt(expression.length() - 1)) || expression.charAt(expression.length() - 1) == ')') && !pause) {
>>>>>>> 077949ecaa7b54625af5a06424f35acf17c622c2
            pc = new PostFix(expression);
            calc = new Calculator(pc.getPostfixAsList());
            answer = Double.toString(calc.result());
        }
    }

    public void clear() {
        expression = "";
        answer = "";
        TextInput.setText(expression);
        TextOutput.setText(answer);
    }

    public String toExpression(String expression) {
        if (expression.length() > 1 && expression.charAt(0) == '0') {
            expression = expression.substring(1, expression.length());
        }
        if (expression.indexOf('*') != -1) {
            expression = expression.replace('*', '×');
        }
        if (expression.indexOf('/') != -1) {
            expression = expression.replace('/', '÷');
        }
        return expression;
    }

    public String toCalculate(String expression) {
        if (expression.length() > 0 && expression.charAt(0) == '-') {
            expression = "0" + expression;
            expression = expression.replace('×', '*');
        }
        if (expression.length() > 0 && expression.indexOf('×') != -1) {
            expression = expression.replace('×', '*');
        }
        if (expression.indexOf('÷') != -1) {
            expression = expression.replace('÷', '/');
        }
        return expression;
    }

    public boolean checkValid(String expression) {
        for (int i = 1; i < expression.length(); i++) {
<<<<<<< HEAD
            if (expression.charAt(i) == '+' || expression.charAt(i) == '-' || expression.charAt(i) == '*' || expression.charAt(i) == '/' || expression.charAt(i) == '^' || expression.charAt(i) == 'f' || expression.charAt(i) == 'c'
                    || expression.charAt(i) == 's' || expression.charAt(i) == 't' || expression.charAt(i) == 'l') {
                if (expression.charAt(i-1) == '+' || expression.charAt(i-1) == '-' || expression.charAt(i-1) == '*' || expression.charAt(i-1) == '/' || expression.charAt(i-1) == '^' || expression.charAt(i-1) == 'f' ||  expression.charAt(i-1) == 'c'
=======
            if (expression.charAt(i) == '+' || expression.charAt(i) == '-' || expression.charAt(i) == '*' || expression.charAt(i) == '/' || expression.charAt(i) == '^' || expression.charAt(i) == 'c'
                    || expression.charAt(i) == 's' || expression.charAt(i) == 't' || expression.charAt(i) == 'l') {
                if (expression.charAt(i-1) == '+' || expression.charAt(i-1) == '-' || expression.charAt(i-1) == '*' || expression.charAt(i-1) == '/' || expression.charAt(i-1) == '^' || expression.charAt(i-1) == 'c'
>>>>>>> 077949ecaa7b54625af5a06424f35acf17c622c2
                        || expression.charAt(i-1) == 's' || expression.charAt(i-1) == 't' || expression.charAt(i-1) == 'l') {
                    clear();
                    TextInput.setText("Error");
                    return false;
                }
            }
        }
        return true;
    }
}