//
// Created by Student on 05.05.17.
//

#ifndef ANDROID_LAB1_MYSQLITE_H
#define ANDROID_LAB1_MYSQLITE_H


public class MySQLite extends SQLiteOpenHelper{

private static final int DATABASE_VERSION = 1;

public MySQLite(Context context){
super(context,"animalsDB",null,DATABASE_VERSION);
}

@Override
public void onCreate(SQLiteDatabase database) {
String DATABASE_CREATE = "create table animals " +"(_id integer primary key autoincrement,"+
"gatunek text not null,"+"kolor text not null,"+"wielkosc real not null,"+"opis text not null);";
database.execSQL(DATABASE_CREATE);
}

@Override
public voidonUpgrade(SQLiteDatabase db,intoldVersion, intnewVersion) {
db.execSQL("DROP TABLE IF EXISTS animals");
onCreate(db);
}

public void dodaj(Animal zwierz){
SQLiteDatabase db = this.getWritableDatabase();
ContentValues values = new ContentValues();
values.put("gatunek",zwierz.getGatunek());
values.put("kolor",zwierz.getKolor());
values.put("wielkosc",zwierz.getWielkosc());
values.put("opis",zwierz.getOpis());
db.insert("animals", null,values);
db.close();
}

public void usun(String id) {
SQLiteDatabase db = this.getWritableDatabase();
db.delete("animals", "_id = ?",
newString[] {id});
db.close();
}

public int aktualizuj(Animal zwierz) {
SQLiteDatabase db =this.getWritableDatabase();
ContentValues values =new ContentValues();
values.put("gatunek",zwierz.getGatunek());
values.put("kolor",zwierz.getKolor());
values.put("wielkosc",zwierz.getWielkosc());
values.put("opis",zwierz.getOpis());
int i = db.update("animals",values,"_id =
?", new String[]{String.valueOf(zwierz.getId())});
     db.close();
     return i;
     }

  public Animal pobierz(int id){
  SQLiteDatabase db =  this.getReadableDatabase();
  Cursor cursor =db.query("animals", //a. table name
  new String[] {"_id","gatunek","kolor","wielkosc","opis"} , // b. column names
  " id = ?",// c. selections
  new String[] {
  String.valueOf (id) },// d. selections args
  null,// e. group by
  null,// f. having
  null,// g. order by
  null);// h. limit
  if(cursor != null )
  cursor.moveToFirst() ;
  Animal zwierz =new Animal(cursor.getString(1),
  cursor.getString(2),cursor.getFloat(3),cursor.getString(4));
  zwierz.setId(Integer.parseInt(cursor.getString(0 )) ) ;
  return zwierz;
  }

public Cursor lista(){
SQLiteDatabase db =  this.getReadableDatabase();
return db.rawQuery("Select * from animals",null);
}

this.adapter =
new SimpleCursorAdapter(
this,android.R.layout.simple_list_item_2, db.lista(),
new String[] {"_id","gatunek"},
new int[] {android.R.id.text1, android.R.id.text2},
SimpleCursorAdapter.IGNORE_ITEM_VIEW_TYPE);

};



#endif //ANDROID_LAB1_MYSQLITE_H
