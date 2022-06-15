import java.awt.*;
import java.util.HashMap;
import java.util.concurrent.atomic.AtomicReference;
import java.util.regex.Pattern;
import javax.script.ScriptEngine;
import javax.script.ScriptEngineManager;
import javax.script.ScriptException;
import javax.swing.*;

public class Main {

  private static final Pattern patternFunc = Pattern.compile("(?<=[^a-zA-Z])([a-z]{3,})(?=[^a-zA-Z])");

  public static void main(String[] args) {
    AtomicReference<Double> memoryVal = new AtomicReference<>((double) 0);
    ScriptEngine engine = new ScriptEngineManager().getEngineByName("js");

    JFrame frame = new JFrame("Calculator");
    Container container = frame.getContentPane();
    container.setLayout(null);

    JPanel panelTextField = new JPanel(new FlowLayout());
    panelTextField.setBounds(0, 0, 600, 30);
    JTextField textField = new JTextField(52);
    panelTextField.add(textField);
    container.add(panelTextField);

    JPanel panelButtonMemory = new JPanel(new GridLayout(1, 5));
    panelButtonMemory.setBounds(0, 30, 600, 50);
    Buttons.buttonMapMemory
      .get("MC")
      .addActionListener(e -> {
        memoryVal.set(.0);
      });
    Buttons.buttonMapMemory
      .get("MR")
      .addActionListener(e -> {
        textField.setText(String.valueOf(memoryVal.get()));
      });
    Buttons.buttonMapMemory
      .get("M+")
      .addActionListener(e -> {
        memoryVal.updateAndGet(v -> v + Double.parseDouble(textField.getText()));
      });
    Buttons.buttonMapMemory
      .get("M-")
      .addActionListener(e -> {
        memoryVal.updateAndGet(v -> v - Double.parseDouble(textField.getText()));
      });
    Buttons.buttonMapMemory
      .get("MS")
      .addActionListener(e -> {
        memoryVal.set(Double.parseDouble(textField.getText()));
      });
    for (String text : Buttons.OPERAND_MEMORY) panelButtonMemory.add(Buttons.buttonMapMemory.get(text));
    container.add(panelButtonMemory);

    JPanel panelButtonAdvanced = new JPanel(new GridLayout(4, 5));
    panelButtonAdvanced.setBounds(0, 100, 600, 300);
    for (String text : Buttons.OPERAND_ADVANCED_FRONT) {
      Buttons.buttonMapAdvancedFront
        .get(text)
        .addActionListener(e -> {
          textField.setText(text + "(" + textField.getText() + ")");
        });
    }
    for (String text : Buttons.OPERAND_ADVANCED_BACK) {
      Buttons.buttonMapAdvancedBack
        .get(text)
        .addActionListener(e -> {
          textField.setText(textField.getText() + text);
        });
    }
    for (String text : Buttons.OPERAND_ADVANCED_BACK) panelButtonAdvanced.add(Buttons.buttonMapAdvancedBack.get(text));
    for (String text : Buttons.OPERAND_ADVANCED_FRONT) panelButtonAdvanced.add(Buttons.buttonMapAdvancedFront.get(text));
    container.add(panelButtonAdvanced);

    JPanel panelButtonBasic = new JPanel(new GridLayout(4, 4));
    panelButtonBasic.setBounds(0, 400, 600, 200);
    for (String text : Buttons.OPERAND_BASIC) {
      Buttons.buttonMapBasic
        .get(text)
        .addActionListener(
          text.equals("=")
            ? e -> {
              try {
                String queryText = patternFunc.matcher(" " + proceedPow(textField.getText()) + " ").replaceAll("Math.$1").trim();
                System.out.println("Calculating: " + queryText);
                textField.setText(engine.eval(queryText).toString());
                System.out.println("Finished.");
              } catch (ScriptException ex) {
                textField.setText(ex.getMessage());
                throw new RuntimeException(ex);
              }
            }
            : e -> {
              textField.setText(textField.getText() + text);
            }
        );
    }
    for (String text : Buttons.OPERAND_BASIC) panelButtonBasic.add(Buttons.buttonMapBasic.get(text));
    container.add(panelButtonBasic);

    frame.setSize(606, 635);
    frame.setResizable(false);
    frame.setLocationRelativeTo(null);
    frame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
    frame.setVisible(true);
  }

  private static String proceedPow(String str) {
    int idx = str.indexOf('^');
    while (idx != -1) {
      int l = idx - 1, r = idx + 1;
      int cnt = 0;
      boolean f = false;
      while (l > 0) {
        char nowChar = str.charAt(l);
        --l;
        if (nowChar == ')') {
          ++cnt;
          if (!f) f = true;
          continue;
        }
        if (nowChar == '(') {
          --cnt;
          if (f && cnt == 0) break;
          continue;
        }
        if (Character.isDigit(nowChar) || Character.isAlphabetic(nowChar)) continue;
        if (cnt == 0) {
          ++l;
          break;
        }
      }
      cnt = 0;
      while (r < str.length() - 1) {
        char nowChar = str.charAt(r);
        ++r;
        if (nowChar == '(') {
          ++cnt;
          if (!f) f = true;
          continue;
        }
        if (nowChar == ')') {
          --cnt;
          if (f && cnt == 0) break;
          continue;
        }
        if (Character.isDigit(nowChar) || Character.isAlphabetic(nowChar)) continue;
        if (cnt == 0) {
          --r;
          break;
        }
      }
      str = str.substring(0, l + 1) + "pow(" + str.substring(l + 1, idx) + "," + str.substring(idx + 1, r) + ")" + str.substring(r);
      idx = str.indexOf('^');
    }
    return str;
  }
}

final class Buttons {

  public static final String[] OPERAND_MEMORY = { "MC", "MR", "M+", "M-", "MS" };
  public static final String[] OPERAND_ADVANCED_FRONT = { "1/", "sqrt", "round", "ceil", "floor", "abs", "exp", "2^", "10^", "log", "sin", "cos", "tan", "asin", "acos", "atan" };
  public static final String[] OPERAND_ADVANCED_BACK = { "^", "(", ")", "%" };
  public static final String[] OPERAND_BASIC = { "7", "8", "9", "+", "4", "5", "6", "-", "1", "2", "3", "*", ".", "0", "=", "/" };

  public static HashMap<String, JButton> buttonMapMemory = new HashMap<>();
  public static HashMap<String, JButton> buttonMapAdvancedFront = new HashMap<>();
  public static HashMap<String, JButton> buttonMapAdvancedBack = new HashMap<>();
  public static HashMap<String, JButton> buttonMapBasic = new HashMap<>();

  static {
    for (String text : OPERAND_MEMORY) buttonMapMemory.put(text, new JButton(text));
    for (String text : OPERAND_ADVANCED_BACK) buttonMapAdvancedBack.put(text, new JButton(text));
    for (String text : OPERAND_ADVANCED_FRONT) buttonMapAdvancedFront.put(text, new JButton(text));
    for (String text : OPERAND_BASIC) buttonMapBasic.put(text, new JButton(text));
  }
}
