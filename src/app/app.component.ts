import { AfterViewInit, Component, OnInit } from '@angular/core';
import { RouterOutlet } from '@angular/router';
import { Browser } from '@capacitor/browser';


@Component({
  selector: 'app-root',
  standalone: true,
  imports: [RouterOutlet],
  templateUrl: './app.component.html',
  styleUrl: './app.component.scss'
})
export class AppComponent  {
  title = 'capacitor-angular-17';

  redirectToPayment(){
    Browser.open({ url: 'https://sandbox.doku.com:/checkout-link-v2/43903889c7c7411484ed6f18a5be7d0e20244812084849658' });
  }
}
