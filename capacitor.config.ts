import type { CapacitorConfig } from '@capacitor/cli';

const config: CapacitorConfig = {
  appId: 'capacitor.angular.17',
  appName: 'capacitor-angular-17',
  webDir: 'www/browser',
  server:{
    allowNavigation:['*']
  },
  android:{
    webContentsDebuggingEnabled: true,
    allowMixedContent: true,
    backgroundColor: '#ffffff',
    appendUserAgent: "android CustomerApp/1.0.0 android ManulifeVietnamApp/1.0.0"
  },
  ios:{
    allowsLinkPreview: true,
    contentInset: "always",
    limitsNavigationsToAppBoundDomains: true,
    preferredContentMode: "mobile",
    appendUserAgent: "iOS CustomerApp/1.0.0 iOS ManulifeVietnamApp/1.0.0"
  },
};

export default config;
