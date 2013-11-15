#include <cairo.h>
#include <gtk/gtk.h>
#include <math.h>
#include <stdio.h>
#include <malloc.h>

gint sec,min,hour,houra,mina,seca,hourb,minb,secb;
gint *hour_arr,*hour_brr,*min_arr,*min_brr,*sec_arr,*sec_brr;
gint a;
char buf[100];
GtkWidget *darea;
 double minutes;
 double seconds;
 double hours;

int binum(int n,int* arr)
{
        int i;
        
        arr[3]=n%2;
        n=n/2;
        arr[2]=n%2;
        n=n/2;
        arr[1]=n%2;
        n=n/2;
        arr[0]=n%2;
        return 0;
        
}


static gboolean
time_vals(GtkWidget *widget)
{
  if (widget->window == NULL) return FALSE;

  time_t curtime;
  struct tm *loctime;

  curtime = time(NULL);
  loctime = localtime(&curtime);
  strftime(buf, 256, "%T", loctime);
  hours=loctime->tm_hour;
  minutes=loctime->tm_min;
  seconds=loctime->tm_sec;

        
        int m,n,o;
        time_t second;
        time_t theTime = time(NULL);
        struct tm *aTime = localtime(&theTime);
        second = time (NULL);
        second=(second+19800);
        m=(second/86400);
        n=(second-(m*86400));
        hour=(n/3600);
        houra=(hour/10);
        hourb=(hour % 10);
        o=(n-(hour*3600));
        min=(o/60);
        mina=(min/10);
        minb=(min%10);
        sec=(o-(min*60));
        secb=(sec % 10);
        seca=(sec/10);

        sec_arr= (int*) malloc (4*sizeof (int));
        sec_brr= (int*) malloc (4*sizeof (int));
        min_arr= (int*) malloc (4*sizeof (int));
        min_brr= (int*) malloc (4*sizeof (int));
        hour_arr= (int*) malloc (4*sizeof (int));
        hour_brr= (int*) malloc (4*sizeof (int));
        binum(houra,hour_arr);
        binum(hourb,hour_brr);
        binum(mina,min_arr);
        binum(minb,min_brr);
        binum(seca,sec_arr);
        binum(secb,sec_brr);
  gtk_widget_queue_draw(widget);
  return TRUE;
}
        

static gboolean on_expose_event(GtkWidget *widget, GdkEventExpose *event,  gpointer data)
{
//ifff a====0
         cairo_t *cr;
          cr = gdk_cairo_create(widget->window);
                
        if(a==0)
        {
                 cairo_set_source_rgb(cr, 0, 0, 0);
                  cairo_select_font_face(cr, "Sans", CAIRO_FONT_SLANT_NORMAL,
             CAIRO_FONT_WEIGHT_NORMAL);
                  cairo_set_font_size(cr, 40.0);

                  cairo_move_to(cr, 70, 100);
                  cairo_show_text(cr, buf);

        }
//iffff a===1
        if(a==1)
        {
        int i;

        cairo_set_source_rgb(cr, 0 , 0 , 0 );
        cairo_set_line_width(cr, 6 );
        cairo_arc(cr, 150, 100, 75, 0, 2 * M_PI);
        cairo_stroke_preserve(cr);
        /*cairo_set_source_rgb(cr, 0.3, 0.4, 0.6); 
        cairo_fill(cr);        */

        for(i=0;i<12;i++)
        {
                cairo_set_source_rgb(cr, 0, 0, 0);
                  cairo_set_line_width(cr, 4 );
                cairo_set_line_cap(cr, CAIRO_LINE_CAP_ROUND); 

                cairo_move_to(cr,150 + 66.5 * cos(i * M_PI / 6),100 + 66.5 * sin(i * M_PI / 6 ));
                cairo_line_to(cr,150 + 75 * cos(i * M_PI / 6),100 + 75 * sin(i * M_PI / 6 ));
                cairo_stroke(cr);
        }

        for(i=0;i<12;i+=3)
        {
                cairo_set_source_rgb(cr, 0, 0, 0);
                  cairo_set_line_width(cr, 7 );
                cairo_set_line_cap(cr, CAIRO_LINE_CAP_ROUND); 

                cairo_move_to(cr,150 + 65.5 * cos(i * M_PI / 6),100 + 65.5 * sin(i * M_PI / 6 ));
                cairo_line_to(cr,150 + 75 * cos(i * M_PI / 6),100 + 75 * sin(i * M_PI / 6 ));
                cairo_stroke(cr);
        }


         minutes = minutes * M_PI / 30;
          hours = hours * M_PI / 6;
          seconds=seconds * M_PI / 30;

        cairo_set_source_rgb(cr,0.3,0.6,0.2);
        cairo_set_line_cap(cr, CAIRO_LINE_CAP_ROUND); 
        cairo_set_line_width(cr, 8  );
        cairo_move_to(cr,150 ,100);
        cairo_line_to(cr,150 + 30 * sin(hours + minutes / 12.0),100 + 40 * -1*cos(hours + minutes / 12.0));
        cairo_stroke(cr);        

        cairo_set_source_rgb(cr, 0.3, 0.4, 0.6);
        cairo_set_line_cap(cr, CAIRO_LINE_CAP_ROUND); 
        cairo_set_line_width(cr, 6 );
        cairo_move_to(cr,150 ,100);
        cairo_line_to(cr,150 + 60 * sin(minutes + seconds / 60),100 + 60 * -1*cos(minutes + seconds / 60));
        cairo_stroke(cr);

        cairo_set_source_rgb(cr, 0.6, 0.6, 0.6);
        cairo_set_line_width(cr, 2.5 );
        cairo_set_line_cap(cr, CAIRO_LINE_CAP_ROUND); 
        cairo_move_to(cr,150 ,100);
        cairo_line_to(cr,150 + 70 * sin(seconds),100 + 60*-1 * cos(seconds));
        cairo_stroke(cr);

        cairo_set_source_rgb(cr, 0 , 0 , 0 );
        cairo_set_line_width(cr, 2 );
        cairo_arc(cr, 150, 100, 1.5, 0, 2 * M_PI);
        cairo_stroke_preserve(cr);
        }

        if (a==2)
        {
        

        cairo_set_line_width(cr, 4);  
        cairo_set_source_rgb(cr, 0.69, 0.19, 0);
        cairo_translate(cr, 50, 120);
        cairo_arc(cr, 0, 0, 10, 0, 2 * M_PI);
        cairo_stroke_preserve(cr);
        if(hour_arr[2]==0)
        cairo_set_source_rgb(cr, 0.8, 0.8, 0.8); 
        else if(hour_arr[2]==1)
        cairo_set_source_rgb(cr, 0, 0, 0); 
        cairo_fill(cr);

        cairo_set_line_width(cr, 4);  
        cairo_set_source_rgb(cr, 0.69, 0.19, 0);
        cairo_translate(cr, 0, 35);
        cairo_arc(cr, 0, 0, 10, 0, 2 * M_PI);
        cairo_stroke_preserve(cr);
        if(hour_arr[3]==0)
        cairo_set_source_rgb(cr, 0.8, 0.8, 0.8); 
        else if(hour_arr[3]==1)
        cairo_set_source_rgb(cr, 0, 0, 0); 
        cairo_fill(cr); 

        cairo_set_line_width(cr, 4);  
        cairo_set_source_rgb(cr, 0.69, 0.19, 0);
        cairo_translate(cr, 35, 0);
        cairo_arc(cr, 0, 0, 10, 0, 2 * M_PI);
        cairo_stroke_preserve(cr);
        if(hour_brr[3]==0)
        cairo_set_source_rgb(cr, 0.8, 0.8, 0.8); 
        else if(hour_brr[3]==1)
        cairo_set_source_rgb(cr, 0, 0, 0); 
        cairo_fill(cr); 

        cairo_set_line_width(cr, 4);  
        cairo_set_source_rgb(cr, 0.69, 0.19, 0);
        cairo_translate(cr, 0, -35);
        cairo_arc(cr, 0, 0, 10, 0, 2 * M_PI);
        cairo_stroke_preserve(cr);
        if(hour_brr[2]==0)
        cairo_set_source_rgb(cr, 0.8, 0.8, 0.8); 
        else if(hour_brr[2]==1)
        cairo_set_source_rgb(cr, 0, 0, 0); 
        cairo_fill(cr);

        cairo_set_line_width(cr, 4);  
        cairo_set_source_rgb(cr, 0.69, 0.19, 0);
        cairo_translate(cr, 0, -35);
        cairo_arc(cr, 0, 0, 10, 0, 2 * M_PI);
        cairo_stroke_preserve(cr);
        if(hour_brr[1]==0)
        cairo_set_source_rgb(cr, 0.8, 0.8, 0.8); 
        else if(hour_brr[1]==1)
        cairo_set_source_rgb(cr, 0, 0, 0); 
        cairo_fill(cr);

        cairo_set_line_width(cr, 4);  
        cairo_set_source_rgb(cr, 0.69, 0.19, 0);
        cairo_translate(cr, 0, -35);
        cairo_arc(cr, 0, 0, 10, 0, 2 * M_PI);
        cairo_stroke_preserve(cr);
        if(hour_brr[0]==0)
        cairo_set_source_rgb(cr, 0.8, 0.8, 0.8);  
        else if(hour_brr[0]==1)
        cairo_set_source_rgb(cr, 0, 0, 0); 
        cairo_fill(cr);

        cairo_set_line_width(cr, 4);  
        cairo_set_source_rgb(cr, 0.69, 0.19, 0);
        cairo_translate(cr, 50, 35);
        cairo_arc(cr, 0, 0, 10, 0, 2 * M_PI);
        cairo_stroke_preserve(cr);
        if(min_arr[1]==0)
        cairo_set_source_rgb(cr, 0.8, 0.8, 0.8); 
        else if(min_arr[1]==1)
        cairo_set_source_rgb(cr, 0, 0, 0); 
        cairo_fill(cr);

        cairo_set_line_width(cr, 4);  
        cairo_set_source_rgb(cr, 0.69, 0.19, 0);
        cairo_translate(cr, 0, 35);
        cairo_arc(cr, 0, 0, 10, 0, 2 * M_PI);
        cairo_stroke_preserve(cr);
        if(min_arr[2]==0)
        cairo_set_source_rgb(cr, 0.8, 0.8, 0.8); 
        else if(min_arr[2]==1)
        cairo_set_source_rgb(cr, 0, 0, 0); 
        cairo_fill(cr);

        cairo_set_line_width(cr, 4);  
        cairo_set_source_rgb(cr, 0.69, 0.19, 0);
        cairo_translate(cr, 0, 35);
        cairo_arc(cr, 0, 0, 10, 0, 2 * M_PI);
        cairo_stroke_preserve(cr);
        if(min_arr[3]==0)
        cairo_set_source_rgb(cr, 0.8, 0.8, 0.8); 
        else if(min_arr[3]==1)
        cairo_set_source_rgb(cr, 0, 0, 0); 
        cairo_fill(cr);

        cairo_set_line_width(cr, 4);  
        cairo_set_source_rgb(cr, 0.69, 0.19, 0);
        cairo_translate(cr, 35,0 );
        cairo_arc(cr, 0, 0, 10, 0, 2 * M_PI);
        cairo_stroke_preserve(cr);
        if(min_brr[3]==0)
        cairo_set_source_rgb(cr, 0.8, 0.8, 0.8); 
        else if(min_brr[3]==1)
        cairo_set_source_rgb(cr, 0, 0, 0); 
        cairo_fill(cr);

        cairo_set_line_width(cr, 4);  
        cairo_set_source_rgb(cr, 0.69, 0.19, 0);
        cairo_translate(cr, 0, -35);
        cairo_arc(cr, 0, 0, 10, 0, 2 * M_PI);
        cairo_stroke_preserve(cr);
        if(min_brr[2]==0)
        cairo_set_source_rgb(cr, 0.8, 0.8, 0.8); 
        else if(min_brr[2]==1)
        cairo_set_source_rgb(cr, 0, 0, 0); 
        cairo_fill(cr);

        cairo_set_line_width(cr, 4);  
        cairo_set_source_rgb(cr, 0.69, 0.19, 0);
        cairo_translate(cr, 0, -35);
        cairo_arc(cr, 0, 0, 10, 0, 2 * M_PI);
        cairo_stroke_preserve(cr);
        if(min_brr[1]==0)
        cairo_set_source_rgb(cr, 0.8, 0.8, 0.8);  
        else if(min_brr[1]==1)
        cairo_set_source_rgb(cr, 0, 0, 0); 
        cairo_fill(cr);

        cairo_set_line_width(cr, 4);  
        cairo_set_source_rgb(cr, 0.69, 0.19, 0);
        cairo_translate(cr, 0, -35);
        cairo_arc(cr, 0, 0, 10, 0, 2 * M_PI);
        cairo_stroke_preserve(cr);
        if(min_brr[0]==0)
        cairo_set_source_rgb(cr, 0.8, 0.8, 0.8);  
        else if(min_brr[0]==1)
        cairo_set_source_rgb(cr, 0, 0, 0); 
        cairo_fill(cr);

        cairo_set_line_width(cr, 4);  
        cairo_set_source_rgb(cr, 0.69, 0.19, 0);
        cairo_translate(cr, 50, 35);
        cairo_arc(cr, 0, 0, 10, 0, 2 * M_PI);
        cairo_stroke_preserve(cr);
        if(sec_arr[1]==0)
        cairo_set_source_rgb(cr, 0.8, 0.8, 0.8);  
        else if(sec_arr[1]==1)
        cairo_set_source_rgb(cr, 0, 0, 0); 
        cairo_fill(cr);

        cairo_set_line_width(cr, 4);  
        cairo_set_source_rgb(cr, 0.69, 0.19, 0);
        cairo_translate(cr, 0, 35);
        cairo_arc(cr, 0, 0, 10, 0, 2 * M_PI);
        cairo_stroke_preserve(cr);
        if(sec_arr[2]==0)
        cairo_set_source_rgb(cr, 0.8, 0.8, 0.8);  
        else if(sec_arr[2]==1)
        cairo_set_source_rgb(cr, 0, 0, 0); 
        cairo_fill(cr);

        cairo_set_line_width(cr, 4);  
        cairo_set_source_rgb(cr, 0.69, 0.19, 0);
        cairo_translate(cr, 0, 35);
        cairo_arc(cr, 0, 0, 10, 0, 2 * M_PI);
        cairo_stroke_preserve(cr);
        if(sec_arr[3]==0)
        cairo_set_source_rgb(cr, 0.8, 0.8, 0.8); 
        else if(sec_arr[3]==1)
        cairo_set_source_rgb(cr, 0, 0, 0); 
        cairo_fill(cr);

        cairo_set_line_width(cr, 4);  
        cairo_set_source_rgb(cr, 0.69, 0.19, 0);
        cairo_translate(cr, 35,0 );
        cairo_arc(cr, 0, 0, 10, 0, 2 * M_PI);
        cairo_stroke_preserve(cr);
        if(sec_brr[3]==0)
        cairo_set_source_rgb(cr, 0.8, 0.8, 0.8); 
        else if(sec_brr[3]==1)
        cairo_set_source_rgb(cr, 0, 0, 0); 
        cairo_fill(cr);

        cairo_set_line_width(cr, 4);  
        cairo_set_source_rgb(cr, 0.69, 0.19, 0);
        cairo_translate(cr, 0, -35);
        cairo_arc(cr, 0, 0, 10, 0, 2 * M_PI);
        cairo_stroke_preserve(cr);
        if(sec_brr[2]==0)
        cairo_set_source_rgb(cr, 0.8, 0.8, 0.8); 
        else if(sec_brr[2]==1)
        cairo_set_source_rgb(cr, 0, 0, 0); 
        cairo_fill(cr);

        cairo_set_line_width(cr, 4);  
        cairo_set_source_rgb(cr, 0.69, 0.19, 0);
        cairo_translate(cr, 0, -35);
        cairo_arc(cr, 0, 0, 10, 0, 2 * M_PI);
        cairo_stroke_preserve(cr);
        if(sec_brr[1]==0)
        cairo_set_source_rgb(cr, 0.8, 0.8, 0.8);  
        else if(sec_brr[1]==1)
        cairo_set_source_rgb(cr, 0, 0, 0); 
        cairo_fill(cr);

        cairo_set_line_width(cr, 4);  
        cairo_set_source_rgb(cr, 0.69, 0.19, 0);
        cairo_translate(cr, 0, -35);
        cairo_arc(cr, 0, 0, 10, 0, 2 * M_PI);
        cairo_stroke_preserve(cr);
        if(sec_brr[0]==0)
        cairo_set_source_rgb(cr, 0.8, 0.8, 0.8); 
        else if(sec_brr[0]==1)
        cairo_set_source_rgb(cr, 0, 0, 0); 
        cairo_fill(cr);
        
        }
}


static gboolean mouse_clicked(gpointer data)
{
        if(a==0)a=1;
        else if (a==1)a=2;
        else if (a==2)a=0;
        return TRUE;
}

int main (int argc, char *argv[])
{
        a=0;
  GtkWidget *window;
	GtkWidget *calendar;
	GtkWidget *frame;
	GtkWidget *fram;
	GtkWidget *fixed;
  
  gtk_init(&argc, &argv);
	calendar=gtk_calendar_new();
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

  darea = gtk_drawing_area_new();
  
	frame = gtk_frame_new (NULL);
	gtk_frame_set_shadow_type (GTK_FRAME (frame), GTK_SHADOW_IN);
	fram = gtk_frame_new (NULL);
	gtk_frame_set_shadow_type (GTK_FRAME (fram), GTK_SHADOW_IN);


	fixed = gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(window), fixed);

gtk_fixed_put(GTK_FIXED(fixed), frame, 0, 200);
gtk_fixed_put(GTK_FIXED(fixed), fram, 0, 0);

gtk_container_add (GTK_CONTAINER (fram),darea);
  gtk_widget_set_size_request (darea, 300,200);


gtk_container_add (GTK_CONTAINER (frame),calendar);
  gtk_widget_set_size_request (calendar,300,200);
 
  g_signal_connect(darea, "expose-event", G_CALLBACK(on_expose_event), NULL);
  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
  g_signal_connect(darea, "button-press-event",  G_CALLBACK(mouse_clicked), NULL);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
gtk_container_add(GTK_CONTAINER(window), darea);
  gtk_window_set_default_size(GTK_WINDOW(window), 300, 400); 
  gtk_window_set_title(GTK_WINDOW(window), "Clock");
  gtk_widget_set_events (darea, gtk_widget_get_events (darea)| GDK_BUTTON_PRESS_MASK);
                             

        g_timeout_add(250, (GSourceFunc) time_vals, (gpointer) window);
        gtk_widget_show_all(window);
        
        time_vals(window);
 
  gtk_main();

  return 0;
}
