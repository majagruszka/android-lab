//
// Created by Student on 05.05.17.
//

#ifndef ANDROID_LAB1_ANIMAL_H
#define ANDROID_LAB1_ANIMAL_H



class Animal implements Serializable {
private int id;
private String gatunek;
private String kolor;
private float wielkoœæ;
private String opis;


public Animal(){}

public Animal(String gatunek, String kolor, float wielkosc, String opis){
super();
this.gatunek=gatunek;
this.kolor=kolor;
this.wielkosc=wielkosc;
this.opis=opis;
}

}
@Override
public String toString(){
return "Zwierze: [id="+id+",gatunek:="+gatunek+",kolor="+kolor+",wielkoœæ="+wielkosc+"]";
}

public String getOpis(){return opis:)
public String getGatunek(){return gatunek:)
public String getKolor(){return kolor:)
public String getWielkosc(){return wielkosc:)
public String getId(){return id:)
public void setId(int id) {this.id=id;}
#endif //ANDROID_LAB1_ANIMAL_H
