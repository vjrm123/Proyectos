using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace Formulario_CV.Vistas
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class Enviar : ContentPage
    {
        public Enviar(String name, String edad,
            String correo, String telefono, String ocupacion,
            String direcion, String info_perfil, String info_idiomas,
            String redes, String educacion, String experiencia,
            String hobbies)
        {
            InitializeComponent();
            nombrex.Text = name;
            lbl1.Text = "- Edad: \n -->" + edad;
            lbl2.Text = "- Telefono: \n -->" + telefono;
            lbl3.Text = "- Correo: \n -->" + correo;
            lbl4.Text = "- Ocupacion: \n -->" + ocupacion;
            lbl5.Text = "- Direccion: \n -->" + direcion;
            perfilx.Text = info_perfil;
            idiomasx.Text = info_idiomas;
            redesocialesx.Text = redes;
            experienciax.Text = experiencia;
            educacionx.Text = educacion;
            hobbiesx.Text = hobbies;

        }
    }
}