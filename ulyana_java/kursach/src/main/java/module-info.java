module kursach.kursach {
    requires javafx.controls;
    requires javafx.fxml;
    requires java.sql;
    requires java.desktop;


    opens kursach.kursach to javafx.fxml;
    exports kursach.kursach;
}